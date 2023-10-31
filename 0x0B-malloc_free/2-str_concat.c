#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	int i, n, t, k, j;
	char *ar;

	i = 0;
	while (s1[i] != '\0')
		i++;
	n = 0;
	while (s2[n] != '\0')
		n++;

	t = i + n;
	ar = malloc(sizeof(char) * t + 1);
	if (ar == NULL)
		return (NULL);
	for (k = 0; k < i ; k++)
	{
		ar[k] = s1[k];
	}
	for (j = 0; k < t; j++, k++)
	{
		ar[k] = s2[j];
	}

	return (ar);
}
