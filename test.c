#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char buf[512];
	for (;;) {
		printf("Enter your name: ");
		read(0, buf, 64);
		printf("Your name is: %s\n", buf);
	}
	close(0);
}
