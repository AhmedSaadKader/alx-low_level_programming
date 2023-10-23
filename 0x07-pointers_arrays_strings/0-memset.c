#include "main.h"

/**
 * _memset - fills memory with a constant byte
 * @s: memory area pointed to by s
 * @b: constant byte
 * @n: number of bytes of memory to be filled
 *
 * Return: a pointer to a character
 */

char *_memset(char *s, char b, unsigned int n)
{
	char *p = s;
	char byte;
	unsigned int i;

	byte = b;

	for (i = 0; i < n; i++)
	{
		p[i] = byte;
	}

	return (s);
}
