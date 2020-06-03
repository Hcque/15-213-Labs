#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *buf[16];
	
	fgets(buf, 10, stdin);
	if (buf[0] == NULL) {
		printf("no input\n");
	}

	return 0;
}


