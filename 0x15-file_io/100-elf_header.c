#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

/**
 * print_error - prints error
 * @msg: the message to print
 * @exit_no: exit number
*/

void print_error(char *msg, int exit_no)
{
	dprintf(STDERR_FILENO, "%s", msg);
	exit(exit_no);
}

/**
 * check_elf - checks if file is an elf
 * @magic_number: ident of header
 *
 * Return: 1 if elf, -1 if not
*/

int check_elf(unsigned char *magic_number)
{
	if (magic_number[0] != 127 || magic_number[1] != 'E' ||
		magic_number[2] != 'L' || magic_number[3] != 'F')
		return (-1);
	return(1);
}

/**
 * display_elf_header - displays elf header
 * @filename: filename
*/

void display_elf_header(const char *filename)
{
	int fd, rd;
	Elf64_Ehdr *elf_header;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		print_error("Error: Unable to open file\n", 98);
	elf_header = malloc(sizeof(Elf64_Ehdr));
	if (elf_header == NULL)
	{
		close(fd);
		print_error("Error: Can't read file\n", 98);
	}
	rd = read(fd, elf_header, sizeof(Elf64_Ehdr));
	if (rd == -1)
	{
		free(elf_header);
		close(fd);
		print_error("Error: Unable to read ELF header\n", 98);
	}
	if (check_elf(elf_header->e_ident) == -1)
	{
		close(fd);
		print_error("Error: File is not an ELF\n", 98);
	}
	printf("%ld\n", elf_header->e_entry);
	printf("%d\n", elf_header->e_version);
	printf("%d\n", elf_header->e_type);
	printf("%d\n", elf_header->e_flags);
	printf("%d\n", elf_header->e_ehsize);
	printf("%d\n", elf_header->e_phentsize);
	printf("%02x\n", elf_header->e_ident[1]);
	free(elf_header);
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
