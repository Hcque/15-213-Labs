#include <stdio.h>

int main() {
	char buf[8];
	int n = read(0, buf ,sizeof(buf));
	write(1, buf, sizeof(buf));

}


