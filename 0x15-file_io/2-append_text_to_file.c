#include "main.h"
/**
 *append_text_to_file - appends text at the end of a file
 *@filename: a pointer to the text file that should be read
 *@text_content: a pointer to the string that should be written to the file
 *Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_d, bytes_written, strlen = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (strlen = 0; text_content[strlen];)
			strlen++;
	}
	file_d = open(filename, O_WRONLY | O_APPEND);
	bytes_written = write(file_d, text_content, strlen);
	if (file_d == -1 || bytes_written == -1)
		return (-1);
	close(file_d);
	return (1);
}
