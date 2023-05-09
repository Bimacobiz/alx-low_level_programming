#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int file_d);

/**
 *create_buffer - assigns a 1024-byte buffer
 *@file: name of buffer storing chars
 *Return: a pointer to the newly assigned buffer
 */
char *create_buffer(char *file)
{
	char *buffer;

	buf = malloc(sizeof(char) * 1024);
	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't inscribe to %s\n", file);
		exit(99);
	}

	return (buffer);
}
/**
 *close_file - closes the file descriptors
 *@file_d: file descriptor that is being closed
 */
void close_file(int file_d)
{
	int a;

	a = close(file_d);

	if (a == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can not close file_d %d\n", file_d);
		exit(100);
	}
}


/**
 *main - copies the contents that are contained in one file to the other file
 *@argc: the number of arguments that are supplied to the program
 *@argv: the array of pointers that points to the arguments
 *Return: 0 in case of success.
 *
 *exit code 97 in case the argument count is correct
 *exit code 98 in case the file_from cannot be read or does not exist
 *exit code 99 in case the file_to cannot be created or written to
 *exit code 100 in case the file_to or file_from cannot be closed
 */
int main(int argc, char *argv[])
{
	int to, from, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);

	from = open(argv[1], O_RDONLY);
	bytes_read = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || bytes_read == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		bytes_written = write(to, buffer, bytes_read);

		if (to == -1 || bytes_written == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}
		bytes_read = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (bytes_read > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
