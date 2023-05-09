#include "main.h"
/**
 *create_file - creates a file
 *@filename: a pointer to the text file that should be read
 *@text_content: a pointer to the string that should be written to the file
 *Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_d, w, strlen = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (strlen = 0; text_content[strlen];)
			strlen++;
	}

	file_d = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(file_d, text_content, strlen);

	if (file_d == -1 || w == -1)
		return (-1);

	close(file_d);

	return (1);


}
