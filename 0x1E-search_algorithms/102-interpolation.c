#include "search_algos.h"

/**
 * interpolation_search - searches for a value in a sorted array of integers
 * using the interpolation search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elemnts in the array
 * @value: the value to search for
 *
 * Return: the first index where value is located, otherwise -1
*/

int interpolation_search(int *array, size_t size, int value)
{
	size_t pos, low, high;

	low = 0;
	high = size - 1;

	if (array == NULL || size == 0)
		return (-1);

	while (low <= high)
	{
		pos = low + ((
			(high - low) / (array[high] - array[low])) * (value - array[low]));
		if (pos >= size)
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			return (-1);
		}
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (value < array[pos])
			high = pos - 1;
		else if (value > array[pos])
			low = pos + 1;
		else
			return (pos);
	}
	return (-1);
}
