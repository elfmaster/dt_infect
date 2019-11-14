#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char cmd[4096];
	ssize_t b;

	for (;;) {
		printf("mybash$: ");
		fflush(stdout);
		b = read(0, cmd, 4096);
		if (cmd[b - 1] != '\n')
			cmd[b - 1] = '\n';
		system(cmd);
	}
}
