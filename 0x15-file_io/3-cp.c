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
	int fd_from, fd_to, rd, wr;
	char buffer[1024];

	if (filename_from == NULL)
		return (98);
	fd_from = open(filename_from, O_RDONLY);
	if (fd_from == -1)
		return (98);
	fd_to = open(filename_to, O_WRONLY | O_CREAT | O_TRUNC | O_EXCL, 0644);
	if (fd_to == -1)
	{
		fd_to = open(filename_to, O_WRONLY | O_TRUNC);
		if (fd_to == -1)
		{
			close(fd_from);
			return (99);
		}
	}
	while ((rd = read(fd_from, buffer, 1024)) > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr == -1)
		{
			close(fd_from);
			close(fd_to);
			return (99);
		}
	}
	if (rd == -1)
	{
		close(fd_from);
		return (98);
	}
	if (close(fd_to) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_from);
		return (100);
	}
	if (close(fd_from) == -1)
	{
		dprintf(2, "Error: Can't close fd %d\n", fd_to);
		return (100);
	}
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
		dprintf(2, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}
	if (res == 100)
		exit(100);

	return (0);
}
