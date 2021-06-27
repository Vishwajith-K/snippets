#include <stdio.h> // puts
#include <stdlib.h> // exit
#include <signal.h> // signal
#include <unistd.h> // alarm

// This function acts as ISR for
// SIGALRM signal received from OS
// code would continue execution after
// signal has been handled
void alarm_handler(int signo) {
	puts("Alarm rang\a\a\a");
}

void sigint_handler(int signo) {
	puts("Bye!!!");
	exit(0);
}

int main(int argc, char *args[]) {
	signal(SIGALRM, alarm_handler);
	signal(SIGINT, sigint_handler);
	alarm(15); // check `man alarm.2`
	alarm(15); // new value will be set
	while(1); // keep waiting
	return 0;
}
