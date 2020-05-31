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



