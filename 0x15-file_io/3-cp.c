#include "main.h"
/**
 * create_buffer - a function that creates a buffer, allocating 1024 bytes for it.
 * @file: the file name whose chars are stored in the buffer.
 *
 * Return: a pointer to the buffer that has been allocated.
 */
char *create_buffer(char *file)
{
	char *buff;

	buff = malloc(sizeof(char) * 1024);

	if (buff == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Failed to write to %s\n", file);
		exit(99);
	}

	return (buff);
}

/**
 * close_file - function that will close file descriptors.
 * @fd: the file descriptor that needs to be closed.
 */
void close_file(int fd)
{
	int b;

	b = close(fd);

	if (b == -1)
	{
		dprintf(STDERR_FILENO, "Error: Failed to close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - a function that copies the content from one file to another.
 * @argc: the number of arguments that the program receives
 * @argv: an array of pointers to args.
 *
 * Return: 0 if it succeeds.
 *
 * Description: exit code 97-if the number of arguments is incorrect.
 * exit code 98-if the file does not exist or cant be read.
 * exit code 99-if the file cant be created or written to.
 * exit code 100-if closing the file is impossible.
 */
int main(int argc, char *argv[])
{
	int from, to, a, s;
	char *buff;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "used to cp file from file_to\n");
		exit(97);
	}

	buff = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	a = read(from, buff, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || a == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Failed to read from file %s\n", argv[1]);
			free(buff);
			exit(98);
		}

		s = write(to, buff, a);
		if (to == -1 || s == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: failed to write to %s\n", argv[2]);
			free(buff);
			exit(99);
		}

		a = read(from, buff, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (a > 0);

	free(buff);
	close_file(from);
	close_file(to);

	return (0);
}
