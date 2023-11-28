#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * display_elf_header - displays elf header
 * @filename: filename
*/

void display_elf_header(const char *filename)
{
	int fd;
	Elf64_Ehdr elf_header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to open file");
		exit(98);
	}
	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(STDERR_FILENO, "Error: Unable to read ELF header");
		exit(98);
	}
	close(fd);
}

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: list of arguments
 *
 * Return: Always 0;
*/

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename");
		exit(98);
	}

	display_elf_header(argv[1]);

	return (0);
}
