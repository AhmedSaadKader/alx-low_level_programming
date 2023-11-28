#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>

void print_error(char *msg, int exit_no);
int check_elf(unsigned char *magic_number);
void print_magic_number(unsigned char *magic_number);
void print_class(unsigned char *elf_header_id);
void print_data(unsigned char *elf_header_id);
void display_elf_header(const char *filename);

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
	return (1);
}

/**
 * print_magic_number - prints the magic number
 * @magic_number: ident of header
*/

void print_magic_number(unsigned char *magic_number)
{
	int i;

	printf("  Magic:   ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		if (i == EI_NIDENT - 1)
			printf("%02x\n", magic_number[i]);
		else
			printf("%02x ", magic_number[i]);
	}
}

/**
 * print_class - prints class
 * @elf_header_id: class
*/

void print_class(unsigned char *elf_header_id)
{
	printf("  Class:                             ");
	if (elf_header_id[EI_CLASS] == ELFCLASSNONE)
		printf("none\n");
	else if (elf_header_id[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else if (elf_header_id[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else
		printf("<unknown: %x>\n", elf_header_id[EI_CLASS]);
}

/**
 * print_data - prints data
 * @elf_header_id: elf header id
*/

void print_data(unsigned char *elf_header_id)
{
	printf("  Data:                              ");
	if (elf_header_id[EI_DATA] == ELFDATANONE)
		printf("none\n");
	else if (elf_header_id[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (elf_header_id[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", elf_header_id[EI_DATA]);
}

/**
 * print_version - prints version
 * @elf_header_id: header id
*/

void print_version(unsigned char *elf_header_id)
{
	printf("  Version:                           %d", elf_header_id[EI_VERSION]);
	if (elf_header_id[EI_VERSION] == EV_CURRENT)
		printf(" (current)\n");
	else
		printf("\n");
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
	print_magic_number(elf_header->e_ident);
	print_class(elf_header->e_ident);
	print_data(elf_header->e_ident);
	print_version(elf_header->e_ident);
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
