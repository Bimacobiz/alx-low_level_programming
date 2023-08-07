#include "main.h"

/**
 * create_file - it will create a file.
 * @filename: a pointer to the file that should be created.
 * @text_content: a pointer to the string to write to the file.
 *
 * Return: -1 for failure and 1 for success.
 */
int create_file(const char *filename, char *text_content)
{
	int fdvalue, m, strlen = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (strlen = 0; text_content[strlen];)
			strlen++;
	}

	fdvalue = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	m = write(fdvalue, text_content, strlen);

	if (fdvalue == -1 || m == -1)
		return (-1);

	close(fdvalue);

	return (1);
}
