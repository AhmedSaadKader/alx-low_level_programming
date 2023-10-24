#include "main.h"
#include <stdio.h>

/**
 * _strstr - locates a substring
 * @haystack: string to search inside
 * @needle: substring to search for
 *
 * Return: pointer to first character in substring inside string
 */

char *_strstr(char *haystack, char *needle)
{
	int i, n, d, f;
	char *x;

	x = 0;

	/* get length of substring */
	d = 0;
	while (needle[d] != '\0')
		d++;

	/* search in string for first letter in substring */
	for (i = 0; haystack[i] != '\0'; i++)
	{
		if (haystack[i] == needle[0])
		{
			f = i;
			for (n = 0; needle[n] != '\0'; n++, f++)
			{
				if (haystack[f] != needle[n])
					break;
			}
		}
		if (n == d)
		{
			x = &haystack[i];
			break;
		}
	}

	return (x);
}
