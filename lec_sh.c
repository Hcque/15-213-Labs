#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() 
{
	int x = 1;
	pid_t pid = fork();
	/*
	printf("current pid %d\n", getpid());
	printf("%d\n", getppid());
	*/
	if (pid == 0){
		
		printf("a");
	}
	else {
		printf("b");
		waitpid(-1, NULL, 0);
	}
	printf("c");

	exit(0);
}

