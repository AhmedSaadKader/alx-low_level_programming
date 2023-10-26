#include "main.h"

/**
 * wildcmp - compares two strings to check if they are identical
 * @s1: string number one
 * @s2: string number two
 *
 * Return: 1 if strings are identical and 0 if otherwise
 */

int wildcmp(char *s1, char *s2)
{
	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	if (s2[0] == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
	if (s1[0] == s2[0])
		return (wildcmp(s1 + 1, s2 + 1));
	if (s1[0] == '\0' && s2[0] == '*')
		return (wildcmp(s1, s2 + 1);
	return (0);
}
