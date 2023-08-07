#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char *create_buffer(char *file);
void close_file(int file_d);

/**
 * create_buffer - a function that creates a buffer,
 * allocating 1024 bytes for it
 * @file: the file name whose chars are stored in the buffer.
 *
 * Return: a pointer to the buffer that has been allocated.
 */
char *create_buffer(char *file)
{
	char *data_buffer;

	data_buffer = malloc(sizeof(char) * 1024);
	if (data_buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't allocate memory for %s\n", file);
		exit(99);
	}

	return (data_buffer);
}

/**
 * close_file - closes the file descriptor
 * @file_d: file descriptor that is being closed
 */
void close_file(int file_d)
{
	int e;

	e = close(file_d);

	if (e == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_d);
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
	int to, from, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);

	from = open(argv[1], O_RDONLY);
	if (from == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't read from file %s\n", argv[1]);
		free(buffer);
		exit(98);
	}

	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		free(buffer);
		close_file(from);
		exit(99);
	}

	do {
		bytes_read = read(from, buffer, 1024);
		if (bytes_read == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			close_file(from);
			close_file(to);
			exit(98);
		}

		bytes_written = write(to, buffer, bytes_read);
		if (bytes_written == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			close_file(from);
			close_file(to);
			exit(99);
		}
	} while (bytes_read > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
