#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFLEN 256
FILE *outfile;
char mybuf[BUFLEN];

int main() 
{
	char *instring;

	outfile = fopen("write", "w+");
	if (!outfile)
		return -1;
	while (1) {
		instring = fgets(mybuf, BUFLEN, stdin);
		if (!instring || strlen(instring) == 0) break;

		fprintf(stdout, "%s", instring);
		fputs(outfile, instring);

	}
	fclose(outfile);
	return 0;

}

