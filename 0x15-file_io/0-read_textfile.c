#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
/**
 *read_textfile - read contents of a text file then print to posix std output
 *@filename: contains the file to be read
 *@letters: the max no of letters that can be read
 *Return: letters read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *data_buffer;
	ssize_t fdvalue;
	ssize_t t;
	ssize_t m;

	fdvalue = open(filename, O_RDONLY);
	if (fdvalue == -1)
		return (0);
	data_buffer = malloc(sizeof(char) * letters);
	m = read(fdvalue, data_buffer, letters);
	t = write(STDOUT_FILENO, data_buffer, m);

	free(data_buffer);
	close(fdvalue);
	return (t);
}
