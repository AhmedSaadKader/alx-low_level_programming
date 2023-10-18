#include "main.h"
#include <stdio.h>

/**
 * _strcat - concatenates two strings
 * @dest: string to be concatenated to
 * @src: string to be concatenated
 *
 * Return: string of concatenated strings
 */

char *_strcat(char *dest, char *src)
{
	int i; /* length of dest */
	int n; /* length of src */
	int k; /* length of both */
	int l; /* used for string concatenation */

	/* get length of dest string */
	i = 0;
	while (dest[i] != '\0')
		i++;

	/* get length of src string */
	n = 0;
	while (src[n] != '\0')
		n++;

	/* get length of both strings combined */
	k = i + n - 1;

	for (l = 0; i <= k; ++i, l++)
	{
		dest[i] = src[l];
	}

	return (dest);
}
