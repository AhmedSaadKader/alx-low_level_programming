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
	int i, n, k, j;
	char *ar;

	i = 0;
	while (s1[i] != '\0')
		i++;
	n = 0;
	while (s1[n] != '\0')
		n++;

	ar = malloc(sizeof(char) * i + n + 1);
	for (k = 0; k < i ; k++)
	{
		ar[k] = s1[k];
	}
	for (j = 0; k < i + n + 1; j++, k++)
	{
		ar[k] = s2[j];
	}

	return (ar);
}
