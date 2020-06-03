#include <stdio.h>
#define MAXARGS 128
#define MAXLINE 1000

/* Function prototypes */

int main()
{
	char cmdline[MAXLINE];

	while (1) {
		/* Read */
		printf(">");
		fgets(cmdline, MAXLINE, stdin);
	}
	if (feof(stdin)) {
		exit(0);
	}

	return 0;
}

void eval(char *cmdline) 
{
	char *argv[MAXARGS];
	char buf[MAXLINE];
	int bg;
	pid_t pid;

	strcpy(buf, cmdline);
	bg = parseline(buf, argv);
	if (argv[0] == NULL)
		return;
	if (!builtin_cmd(argv)){
		if ((pid = fork()) == 0) {
			execve(argv[0], argv, environ);
		}
		if (!bg) {
			int status;
			waitpid(pid, &status, 0);
		}
		else {
		}

	}
	return;
}

int builtin_cmd(char **argv) 
{
	if (!strcmp(argv[0], "quit"))
		exit(0);
	return 0;
}

int parseline(char *buf, char **argv) 
{


		
		


