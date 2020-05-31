#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() 
{
	pid_t pid = fork();
	if (pid == 0) {
		printf("hello from child process\n");
	}
	else {
		printf("hello from PARENT process\n");
	}
	return 0;

}

