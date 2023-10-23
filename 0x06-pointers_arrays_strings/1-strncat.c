#include "main.h"

/**
 * _strncat - concatenates two strings using at most
 * n bytes from second string
 * @dest: string to be concatenated to
 * @src: string to be concatenated
 * @n: number of characters from the second string
 *
 * Return: concatenated string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i; /* length of dest string */
	int x; /* length of src string */
	int k; /* dest length added to n */
	int l; /* integer to loop through second string */

	i = 0;
	while (dest[i] != '\0')
		i++;

	x = 0;
	while (src[x] != '\0')
		x++;

	k = i + n;

	for (l = 0; i <= k - 1; ++i, l++)
		dest[i] = src[l];

	return (dest);
}
