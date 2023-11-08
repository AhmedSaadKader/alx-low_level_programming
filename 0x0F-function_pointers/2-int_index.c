#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - searches for an integer
 * @array: array to search inside
 * @size: number of elemenets in array
 * @cmp: pointer to the function used to compare the values
 *
 * Return: index of the first element for which the cmp function
 * does not return 0 OR -1 if no element matches OR -1 if size <= 0
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;
	int result;

	if (size <= 0)
	{
		return (-1);
	}
	if (array && cmp)
	{
		for (i = 0; i < size; i++)
			{
				result = cmp(array[i]);
				if (result != 0)
					return (i);
			}
	}
	return (-1);
}
