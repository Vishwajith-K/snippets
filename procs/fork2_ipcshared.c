// a memory will be created by parent
// both parent and child will get attached to same memory
// actual memory on hardware will be same
// makes use of shm* calls

// here parent writes to the memory and child reads from memory

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define BUF_SIZE 100

int main() {
	int pid, shmid;
	char *shmp;

	// parent (this) creates a segment of memory with below flags
	// see `man 2 shmget` bugs section
	// the word private has nothing to do with it's meaning

	// if there's a different process in some place which needs to
	// access same memory, then use same key (1st field) and permissoins
	// except the `IPC_CREAT` flag
	// `man 2 shmop` has example which does not make use of this call twice
	shmid = shmget(IPC_PRIVATE, BUF_SIZE, 0666 | IPC_CREAT);
	if (shmid == -1) {
		puts("Unable to get shared memory id");
		return 0;
	}

	pid = fork();
	if (pid < 0) {
		puts("Forking failed");
	}
	else if (pid) {
		puts("Parent");
		// attach, write some data, `wait` for child to finish
		// detach, remove
		// It's the job of parent clean all mess

		// unsure on how to use second field
		// `man` says that, it can be page aligned address
		// so is it possible to pass `malloc(4096)`?
		// If you know got id of some shmget, it can directly be used
		// to get in sync with same memory
		shmp = shmat(shmid, NULL, 0);
		if (shmp == (void *) -1) {
			puts("Parent: failed to attach to shared memory segment");
			goto rm_segment;
		}
		strcpy(shmp, "Hello");
		wait(NULL);
		shmdt(shmp);
	rm_segment:
		if (shmctl(shmid, IPC_RMID, 0) == -1) {
			puts("Parent: failed to destroy the created memory segment");
		}
	}
	else {
		puts("Child");
		// wait for some time, attach, read, detach
		sleep(1);
		shmp = shmat(shmid, NULL, 0);
		if (shmp == (void *) -1) {
			puts("Child: failed to attach to shared memory segment");
			return 0;
		}
		puts(shmp);
		shmdt(shmp);
	}
	return 0;
}
