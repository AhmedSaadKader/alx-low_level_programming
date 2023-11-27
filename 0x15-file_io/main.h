#ifndef FILE_IO_H
#define FILE_IO_H

#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t read_textfile(const char *filename, size_t letters);
int _putchar(char c);

#endif /* FILE_IO_H */
