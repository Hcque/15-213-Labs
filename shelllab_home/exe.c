#include <stdio.h>
#include <unistd.h>
int main()
{
	char *argv[2];

	argv[0] = "echo";
	argv[1] = "echo";
	argv[2] = 0;

	execl("bin/echo", argv);
}

