#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main() 
{
	int x = 1;
	pid_t pid = fork();
	if (pid == 0) {
		printf("CHILD has x = %d\n", ++x);
	}
	else {
		printf("PARENT has x = %d\n", --x);
	}
		printf("Farewell from process with pid %dnd x = %d\n",
			       	getpid(), x);

	return 0;

}

