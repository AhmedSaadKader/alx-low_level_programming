#include "main.h"
#include <stdlib.h>

/**
 * _strlen - gets the length of the string
 * @s: string
 *
 * Return: length of the string
 */

unsigned int _strlen(char *s)
{
	unsigned int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/**
 * string_nconcat - concatenates first string to first n bytes of
 * second string and null terminated
 * @s1: first string
 * @s2: second string
 * @n: number of bytes of the second string
 *
 * Return: pointer to the concatenated string
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *constring;
	unsigned int s1_len, s2_len;
	unsigned int malloc_size;
	unsigned int i, k;

	if (s1 == NULL)
		s1 = "";

	if (s2 == NULL)
		s2 = "";

	s1_len = _strlen(s1);
	s2_len = _strlen(s2);

	if (n > s2_len)
		malloc_size = s1_len + s2_len + 1;
	else
		malloc_size = s1_len + n + 1;

	constring = malloc(malloc_size);
	if (constring == NULL)
		return (NULL);

	for (i = 0; i < s1_len; i++)
		constring[i] = s1[i];
	for (k = 0; k < n && s2[k] != '\0'; k++, i++)
		constring[i] = s2[k];
	constring[i] = '\0';

	return (constring);
}
