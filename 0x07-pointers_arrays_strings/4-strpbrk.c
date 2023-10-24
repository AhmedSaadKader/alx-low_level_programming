#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to search
 * @accept: set of bytes
 *
 * Return: pointer to the byte in s that matches one of the
 * bytes in accept or NULL if no such byte is found
 */

char *_strpbrk(char *s, char *accept)
{
	int i, n;
	char *x;

	x = 0;

	for (i = 0; s[i] != '\0'; i++)
	{
		for (n = 0; accept[n] != '\0'; n++)
		{
			if (s[i] == accept[n])
			{
				x = &s[i];
				return (x);
			}
		}
	}

	return (x);
}
