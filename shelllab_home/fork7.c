#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() 
{
	if (fork() == 0) {
		printf("terminte child pid = %d", getpid());
		exit(0);
	}
	else {
		printf("running parent, pid = %d", getpid());
		while (1) 
			;
	}

}

