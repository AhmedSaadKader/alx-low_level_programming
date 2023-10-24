#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to get the length of its prefix
 * @accept: prefix to get the length of
 *
 * Return: integer representing the length of the prefix
 */

unsigned int _strspn(char *s, char *accept)
{
	int i, n;
	unsigned int x;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == ' ')
			return (x);
		for (n = 0; accept[i] != '\0'; n++)
		{
			if (s[i] == accept[n])
				x++;
		}
	}
}
