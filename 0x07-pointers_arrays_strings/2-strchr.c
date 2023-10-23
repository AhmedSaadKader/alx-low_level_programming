#include "main.h"

/**
 * _strchr - locates a character in a string
 * @s: string to locate character in
 * @c: character to locate
 *
 * Return: pointer to location of character in string
 */

char *_strchr(char *s, char c)
{
	int i;
	char *x;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
		{
			x = &s[i];
			break;
		}
	}

	if (c == '\0')
		return (s);

	return (x);
}
