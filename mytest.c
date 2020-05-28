#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(int argc, char** argv) 
{
	int s, E, b, isVerbose = 0;
	char tracefileName[100], opt[10];
	int c;
	int addr, size;
	while((c = getopt(argc, argv, "hvs:E:b:t:"))!= -1) {

		//printf("%c, %d\n", c, atoi(optarg));
		switch(c)
		{
		case 'v':
			isVerbose = 1;
			break;
		case 's':
			s = atoi(optarg);
			break;
		case 'E':
			E = atoi(optarg);
			break;
		case 'b':
			b = atoi(optarg);
			break;
		case 't':
			strcpy(tracefileName, optarg);
			break;
		case 'h':
		default:
			exit(0);
		}
	}
	FILE *tracefile = fopen(tracefileName, "r");
	printf("%d\n", tracefile);
	int a = fscanf(tracefile, "%s %x %d", opt, &addr, &size);
	printf("%d", a);
	printf("%s", addr);

	return 0;
}

