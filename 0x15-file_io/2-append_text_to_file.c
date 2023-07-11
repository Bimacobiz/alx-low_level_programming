#include "main.h"

/**
 * append_text_to_file - a function that appends text at the file's end.
 * @filename: points to the file name.
 * @text_content: the string that should be added at the end of the file.
 *
 * Return: -1 in case of failure, or the filename is NULL, file does not
 * exist or the user lacks write permissions.
 * 1 on success.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int p, s, strlen = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (strlen = 0; text_content[strlen];)
			strlen++;
	}

	p = open(filename, O_WRONLY | O_APPEND);
	s = write(p, text_content, strlen);

	if (p == -1 || s == -1)
		return (-1);

	close(p);

	return (1);
}
