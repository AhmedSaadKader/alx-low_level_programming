#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * cp - copies the content of a file to another file
 * @filename_from: filename of file to copy from
 * @filename_to: filename of file to copy to
 *
 * Return: 1 if succeeded, -1 if failed
*/

int cp(const char *filename_from, const char *filename_to)
{
	int fd_from, fd_to;
	int rd, wr;
	int buffer_size = 1024;
	char *buffer;

	if (filename_from == NULL)
		return (98);

	fd_from = open(filename_from, O_RDONLY);
	if (fd_from == -1)
		return (98);
	buffer = malloc(buffer_size);
	if (buffer == NULL)
		return (-1);
	rd = read(fd_from, buffer, buffer_size);
	if (rd == -1)
	{
		close(rd);
		return (98);
	}

	fd_to = open(filename_to, O_WRONLY | O_CREAT, 0644);
	if (fd_to == -1)
		return (99);
	if (buffer != NULL)
	{
		wr = write(fd_to, buffer, rd);
		if (wr == -1)
		{
			close(fd_to);
			return (99);
		}
	}

	free(buffer);
	close(fd_to);
	close(fd_from);
	return (1);
}

/**
 * main - Entry point
 * @ac: number of arguments
 * @av: list of arguments
 *
 * Return: Always 0
*/

int main(int ac, char **av)
{
	int res;

	if (ac != 3)
	{
		dprintf(2, "Usage: cp file_from file_to\n");
		exit(97);
	}
	res = cp(av[1], av[2]);
	if (res == 98)
	{
		dprintf(2, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	if (res == 99)
	{
		dprintf(2, "Can't write to %s", av[2]);
		exit(99);
	}
	return (0);
}
