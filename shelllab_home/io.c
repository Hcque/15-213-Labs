#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
	char fn[] = "fork1.c";
	FILE *fd;
	fd = fopen(fn, "wb");
	char buf[16];
	int num = fread(buf, 16, 1, fd);
	fprintf(stdout, "%s\n", buf);
	fprintf(stdout, "hello world\n");
}

