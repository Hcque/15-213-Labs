#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#define N 2

unsigned int snooze(unsigned int sec) 
{
	unsigned int rs = sleep(sec);
	printf("left %d", sec - rs);

}

int main() 
{
	int status, i;
	pid_t pid;

	snooze(6);

	/* Parent create N child */
	for (i = 0; i < N; i++) {
		if ((pid = fork()) != 0) {
			exit(100+i);
		}
	}
	


}

