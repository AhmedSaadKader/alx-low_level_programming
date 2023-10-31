#include <stdlib.h>
#include "main.h"

/**
 * create_array - creates an array of chars,
 * and initializes it with a specific char
 * @size: integer representing the size of array
 * @char: the specific char
 *
 * Return: pointer to array of char
 */

char *create_array(unsigned int size, char c)
{
	char *ar;
	int i;

	i = 0;
	ar = malloc(sizeof(char) * size);

	while (i < size)
	{
		ar[i] = c;
		i++;
	}
	return (ar);
}
