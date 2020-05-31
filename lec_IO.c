#include <stdio.h>

int main(void)
{
	char c;
	int len;
	while ((len = read(0, &c, 1)) == 1) {
		if (write(1, &c, 1) != 1){
			exit(20);
		}
	}

	if (len < 0) {
		printf("read frm stdin failed");
		exit(10);
	}
}


