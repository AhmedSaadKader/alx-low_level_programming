#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: first value
 * @max: last value
 *
 * Return: the pointer to the created array
 * if min > max or if malloc fails return NULL
 */

int *array_range(int min, int max)
{
	int *arr;
	unsigned int i, len;

	if (min > max)
		return (NULL);

	len = max - min + 1;
	arr = malloc(len * sizeof(int));
	if (arr == NULL)
		return (NULL);
	for (i = 0; i <= len; i++)
		arr[i] = min + i;

	return (arr);
}
