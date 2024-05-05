#include "search_algos.h"

/**
 * linear_search - Searches for a value in an array of
 * integers using the Linear search algorithm
 * @array: array of integers
 * @size: size the number of elements in the array
 * @value: value to search for
 *
 * Return: the first index where value is located or
 * -1 if value is not present or if array is NULL
*/

int linear_search(int *array, size_t size, int value)
{
	size_t i = 0;

	while (i < size)
	{
		printf("Value checked array[%ld] = [%i]\n", i, array[i]);
		if (value == array[i])
			return (i);
		i++;
	}
	return (-1);
}
