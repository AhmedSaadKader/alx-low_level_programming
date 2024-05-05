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
	if (array == NULL || size == 0)
		return (-1);

	return (
		interpolation_search_recursive(array, 0, size, value)
	);
}

/**
 * interpolation_search_recursive - searches for a value in a sorted array of
 * integers using the interpolation search algorithm
 * @array: pointer to the first element of the array
 * @low: starting point of the search
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: the index where the value is located,
 * -1 if value is not present in array of if array is NULL
*/

int interpolation_search_recursive(
	int *array, size_t low, size_t size, int value)
{
	size_t pos, high;

	high = low + size - 1;
	pos = low + ((
			(high - low) / (array[high] - array[low])) * (value - array[low]));

	if (size == 0)
		return (-1);

	if (pos >= size || pos < low || pos > high)
	{
		printf("Value checked array[%ld] is out of range\n", pos);
		return (-1);
	}
	printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);

	if (array[pos] == value)
		return (pos);

	if (array[pos] < value)
		return (
			interpolation_search_recursive(
				array, pos + 1, size - (pos - low + 1), value)
			);
	else
		return (interpolation_search_recursive(
			array, low, pos - low, value));
}
