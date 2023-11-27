#include "main.h"
#include <stdio.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the filename to read the text of
 * @letters: number of letters it should read and print
 *
 * Return: the actual number of letters it read, or 0 if error
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd, sz, i = 0;
	char buffer[1024];

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (!fd)
		return (0);
	sz = read(fd, buffer, letters);
	if (sz == -1)
	{
		close(fd);
		return (0);
	}
	buffer[sz] = '\0';
	while (buffer[i] != '\0')
	{
		_putchar(buffer[i]);
		i++;
	}
	close(fd);
	return (sz);
}
