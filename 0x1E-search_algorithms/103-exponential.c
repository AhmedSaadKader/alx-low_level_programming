#include "search_algos.h"

/**
 * exponential_search - searches for a value in a sorted array of integers
 * using the Exponential search algorithm
 * @array: pointer to the first element of the array to search in
 * @size: the number of elements of the array
 * @value: the value to search for
 *
 * Return: first index where value is located, otherwise -1
*/

int exponential_search(int *array, size_t size, int value)
{
	size_t index = 1, start, end;

	if (array == NULL || size == 0)
		return (-1);

	while (index < size && array[index] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", index, array[index]);
		index *= 2;
	}

	start = index / 2;
	end = (index < size) ? index : size - 1;

	printf("Value found between indexes [%ld] and [%ld]\n", start, end);

	return (
		binary_search_recursive(array, start, (end - start + 1), value)
	);
}

/**
 * binary_search - searches for a value in a sorted array of
 * integers using the binary search algorithm
 * @array: pointer to the first element of the array
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: the index where the value is located,
 * -1 if value is not present in array of if array is NULL
*/

int binary_search(int *array, size_t size, int value)
{
	return (
		binary_search_recursive(array, 0, size, value)
	);
}

/**
 * binary_search_recursive - searches for a value in a sorted array of
 * integers using the binary search algorithm
 * @array: pointer to the first element of the array
 * @low: starting point of the search
 * @size: number of elements in array
 * @value: the value to search for
 *
 * Return: the index where the value is located,
 * -1 if value is not present in array of if array is NULL
*/

int binary_search_recursive(int *array, size_t low, size_t size, int value)
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
		return (mid);

	if (array[mid] < value)
		return (
			binary_search_recursive(array, mid + 1, size - (mid - low + 1), value)
			);
	else
		return (binary_search_recursive(array, low, mid - low, value));
}
