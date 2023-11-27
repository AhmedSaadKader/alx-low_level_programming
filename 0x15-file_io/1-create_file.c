#include "main.h"
#include <string.h>

/**
 * create_file - creates a file
 * @filename: the name of the file to create
 * @text_content: NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
*/

int create_file(const char *filename, char *text_content)
{
	int cf, wr;

	if (filename == NULL)
		return (-1);
	cf = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0600);
	if (cf == -1)
		return (-1);
	if (text_content != NULL)
	{
		wr = write(cf, text_content, strlen(text_content));
		if (wr == -1)
		{
			close(cf);
			return (-1);
		}
	}
	close(cf);
	return (1);
}
