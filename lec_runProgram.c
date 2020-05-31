#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAXARGS 120

int main() 
{
	char cmdline[MAXARGS];
	while (1) {
		printf(">");
		fgets(cmdline, MAXARGS, stdin);
		printf("good job\n");
	}

}

