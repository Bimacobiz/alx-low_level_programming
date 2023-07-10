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
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fdvalue;/*fdvalue is the file descriptor value*/
	ssize_t letters_read;

	char *buffer = malloc((1024)*sizeof(char));
	fdvalue = open(filename, O_RDONLY);

	if (fdvalue == -1)
		return -1;

	letters_read = read(fdvalue, buffer, letters);
	if (letters_read == -1)
	{
		close(fdvalue);
		return -1;
	}

	write(STDOUT_FILENO, buffer, letters_read);
	close(fdvalue);

	return letters_read;
}
