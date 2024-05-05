#include "search_algos.h"

/**
 * advanced_binary - searches for a value in a sorted array of
 * integers using the binary search algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: the index where the value is located,
 * -1 if value is not present in array of if array is NULL
*/

int advanced_binary(int *array, size_t size, int value)
{
	return (
		advanced_binary_recursive(array, 0, size, value)
	);
}

/**
 * advanced_binary_recursive - searches for a value in a sorted array of
 * integers using the binary search algorithm
 * @array: pointer to the first element of the array
 * @low: starting point of the search
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: the index where the value is located,
 * -1 if value is not present in array of if array is NULL
*/

int advanced_binary_recursive(int *array, size_t low, size_t size, int value)
{
	size_t mid, i = low;

	mid = low + ((size - 1) / 2);

	if (size == 0)
		return (-1);

	printf("Searching in array: ");
	while (i < size + low)
	{
		if (i == low + size - 1)
			printf("%i\n", array[i]);
		else
			printf("%i, ", array[i]);
		i++;
	}

	if (array[mid] == value)
	{
		if (mid == low || array[mid - 1] != value)
			return (mid);
		return (
			advanced_binary_recursive(array, low, mid, value)
		);
	}

	if (array[mid] < value)
		return (
			advanced_binary_recursive(array, mid + 1, size - (mid - low + 1), value)
			);
	else
		return (advanced_binary_recursive(array, low, mid - low, value));
}
