#include "main.h"

/**
 * create_file - a function that creates a file.
 * @filename: points to the name of the file that should be created.
 * @text_content: points to the string that should be written to the file.
 *
 * Return: -1 for failure and 1 for success.
 */
int create_file(const char *filename, char *text_content)
{
	int fdvalue, s, strlen = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (strlen = 0; text_content[strlen];)
			strlen++;
	}

	fdvalue = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	s = write(fdvalue, text_content, strlen);

	if (fdvalue == -1 || s == -1)
		return (-1);

	close(fdvalue);

	return (1);
}
