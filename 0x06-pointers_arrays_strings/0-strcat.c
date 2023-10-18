#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: string to be concatenated to
 * @src: string to be concatenated
 *
 * Return: string of concatenated strings
 */

char *_strcat(char *dest, char *src)
{
	int i;

	/* get length of dest string */
	for (i = 0; dest[i] == '\0'; i++);
	printf("%i", i);
}