#include "main.h"

/**
 * check_elf - a function that checks if a document is an ELF file.
 * @e_ident: Points to an array that contains magic numbers of ELF.
 *
 * Description: Exit code 98 if the file is not ELF.
 */
void check_elf(unsigned char *e_ident)
{
	int s; /* s is the index */

	for (s = 0; s < 4; s++)
	{
		if (e_ident[s] != 127 &&
				e_ident[s] != 'E' &&
				e_ident[s] != 'L' &&
				e_ident[s] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: This file is Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - A function that prints ELF header's magic numbers.
 * @e_ident: Points to an array that contains magic numbers of ELF.
 *
 * Description: Magic numbers separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int s;

	printf("  Magic:   ");

	for (s = 0; s < EI_NIDENT; s++)
	{
		printf("%02x", e_ident[s]);

		if (s == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * print_class - Prints the ELF header class.
 * @e_ident: Points to an array that contains magic numbers of ELF.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_data - prints the data that is in the ELF header.
 * @e_ident: Points to an array that contains magic numbers of ELF..
 */
void print_data(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * print_version - prints the ELF header version.
 * @e_ident: Points to an array that contains magic numbers of ELF..
 */
void print_version(unsigned char *e_ident)
{
	printf("  Version:                           %d",
			e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_osabi - A function that printd the OS/ABI of the ELF header.
 * @e_ident: Points to an array that contains magic numbers of ELF..
 */
void print_osabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NetBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - Linux\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - Solaris\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("Standalone App\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * print_type - will prints the ELF header type
 * @e_type: The ELF type.
 * @e_ident: points to an array that contains the the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case ET_DYN:
			printf("DYN (Shared object file)\n");
			break;
		case ET_CORE:
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - a function that prints the ELF header entry point.
 * @e_entry: ELF entry point address.
 * @e_ident: Points to an array that contains the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: FD of  the ELF file.
 *
 * Description: Failed to close the file - exit code 98.
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Displays the info in the ELF header at the beginning ot the ELF file.
 * @argc: Number of arguments the program receives.
 * @argv: An arra of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description:  exit code 98 if the file is not ELF.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int p, n;

	p = open(argv[1], O_RDONLY);
	if (p == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(p);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	n = read(p, header, sizeof(Elf64_Ehdr));
	if (n == -1)
	{
		free(header);
		close_elf(p);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	print_magic(header->e_ident);
	print_class(header->e_ident);
	print_data(header->e_ident);
	print_version(header->e_ident);
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(p);
	return (0);
}

