#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: memory area copied to
 * @src: memory area copied from
 * @n: number of bytes
 *
 * Return: memory pointer to character
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];

	return (dest);
}
