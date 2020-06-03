#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() 
{
	int child_status;

	if (fork() == 0) {
		printf("hi from child\n");
	}
	else {
		printf("hi from parent\n");
		//wait(&child_status);
		printf("byb from child\n");
	}
	printf("byb\n");
	return 0;
}

