#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() 
{
	if (fork() == 0) {
		printf("running child pid = %d", getpid());
		while (1) 
			;
	}
	else {
		printf("terminate parent, pid = %d", getpid());
		exit(0);
	}

}

