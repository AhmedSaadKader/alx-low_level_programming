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
		dprintf(2, "Error: Unable to open file");
		exit(98);
	}
	if (read(fd, &elf_header, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr))
	{
		dprintf(2, "Error: Unable to read ELF header");
		exit(98);
	}
	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
		elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
		elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
		elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(2, "Error: Not an ELF file");
		exit(98);
	}
	printf("Magic:   %02x %02x %02x %02x\n", elf_header.e_ident[EI_MAG0],
			elf_header.e_ident[EI_MAG1],
		   elf_header.e_ident[EI_MAG2], elf_header.e_ident[EI_MAG3]);
	printf("Class:   %s\n", elf_header.e_ident[EI_CLASS] == ELFCLASS64
			? "ELF64" : "ELF32");
	printf("Data:    %s\n", elf_header.e_ident[EI_DATA] == ELFDATA2LSB
			? "2's complement, little endian" : "Unknown data format");
	printf("Version: %d\n", elf_header.e_ident[EI_VERSION]);
	printf("OS/ABI:  %s\n", elf_header.e_ident[EI_OSABI] == ELFOSABI_SYSV
			? "UNIX System V ABI" : "Other ABI");
	printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("Type:    %s\n", elf_header.e_type == ET_EXEC
			? "Executable file" : "Other");
	printf("Entry point address: %#lx\n", (unsigned long)elf_header.e_entry);
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
		dprintf(2, "Usage: elf_header elf_filename");
		exit(98);
	}

	display_elf_header(argv[1]);

	return (0);
}
