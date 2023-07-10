#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
/**
 *read_textfile - reads a text file then prints it to the posix std output
 *@filename: a pointer to the file that the function should read
 *@letters: the maximum number of letter that the function can read
 *Return: letters read
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t fdvalue;
	ssize_t s;
	ssize_t k;

	fdvalue = open(filename, O_RDONLY);
	if (fdvalue == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	k = read(fdvalue, buffer, letters);
	s = write(STDOUT_FILENO, buffer, k);

	free(buffer);
	close(fdvalue);
	return (s);
}
