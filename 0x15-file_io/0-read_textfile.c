#include "main.h"
#include <stdlib.h>
/**
 *read_textfile - reads a text file and prints it to the POSIX standard output
 *@filename: a pointer to the texgt file that should be read
 *@letters: the number of letters that should be read
 *Return: the actual number of letters that it can write and print
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t t;
	ssize_t w;
	ssize_t file_d;

	file_d = open(filename, O_RDONLY);
	if (file_d == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	t = read(file_d, buffer, letters);
	w = write(STDOUT_FILENO, buffer, t);
	free(buffer);
	close(file_d);
	return (w);
}
