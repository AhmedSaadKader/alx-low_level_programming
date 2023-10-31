#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * which contains a copy of a string given as a parameter
 * @str: the string to be copied
 *
 * Return: Pointer to the allocated memory
 */

char *_strdup(char *str)
{
	char *ar;
	int i, n;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	ar = malloc(sizeof(char) * ++i);
	if (ar == NULL)
		return (NULL);
	n = 0;
	while (n < i)
	{
		ar[n] = str[n];
		n++;
	}

	return (ar);
}
