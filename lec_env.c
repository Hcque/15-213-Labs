#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[]) 
{
	int i;
	printf("Command line arguments:\n");
	for (i = 0; argv[i] != NULL; i++) {
		printf("argv[%d]: %s \n", i, argv[i]);
	}

	printf("Environment Variables:\n");
	for (i = 0; envp[i] != NULL; i++) {
		printf("envp[%d]: %s \n", i, envp[i]);
	}
	return 0;

}

