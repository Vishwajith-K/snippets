#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>	// fork - unix standard
#include <sys/wait.h>

int main() {
	int pid;

	pid = fork();
	if (pid < 0)
		puts("Process creation failed");
	else if (pid > 0) {
		printf("This process id: %d\nChild process id: %d\n", pid, getpid());
		wait(NULL); // wait for any of it's child to finish
	}
	else // pid is zero
		printf("Parent process id: %d\nCurrent process id: %d\n", getppid(), getpid());
	return 0;
}
