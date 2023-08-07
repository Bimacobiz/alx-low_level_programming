#include "main.h"

/**
 * append_text_to_file - appends test to a given file.
 * @filename: points to the name of the file
 * @text_content: string to be added to the files end.
 *
 * Return: -1 in case of failure, or the filename is NULL, file does not
 * exist or the user does not have write permissions.
 * 1 on success.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int q, r, strlen = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (strlen = 0; text_content[strlen];)
			strlen++;
	}

	q = open(filename, O_WRONLY | O_APPEND);
	r = write(q, text_content, strlen);

	if (q == -1 || r == -1)
		return (-1);

	close(q);

	return (1);
}
