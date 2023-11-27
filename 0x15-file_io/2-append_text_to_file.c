#include "main.h"
#include <string.h>

/**
 * append_text_to_file - appends a text at the end of a file
 * @filename: the name of the file
 * @text_content: NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
*/

int append_text_to_file(const char *filename, char *text_content)
{
	int open_file, wr;

	if (filename == NULL)
		return (-1);
	open_file = open(filename, O_WRONLY | O_APPEND);
	if (open_file == -1)
		return (-1);
	if (text_content != NULL)
	{
		wr = write(open_file, text_content, strlen(text_content));
		if (wr == -1)
			return (-1);
	}
	close(open_file);
	return(1);
}