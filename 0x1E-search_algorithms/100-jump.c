#include "search_algos.h"

/**
 * jump_search - searches for a value in a sorted array of integers using
 * the Jump search algorithm
 * @array: a pointer to the first element of the array to search in
 * @size: the number of elements in array
 * @value: the value to search for
 *
 * Return: first index where value is located, or -1 if value is not present
 * or if array is NULL
*/

int jump_search(int *array, size_t size, int value)
{
	size_t jump_step, start = 0, end, i;

	if (array == NULL || size == 0)
		return (-1);
	jump_step = sqrt(size);
	while (start < size)
	{
		if ((start + jump_step) < size)
			end = start + jump_step;
		else
			end = size - 1;
		printf("Value checked array[%ld] = [%i]\n", start, array[start]);
		if ((value > array[start]) && (value <= array[end]))
		{
			i = start;
			printf("Value found between indexes [%ld] and [%ld]\n", start, end);
			while (i <= end)
			{
				printf("Value checked array[%ld] = [%i]\n", i, array[i]);
				if (value == array[i])
					return (i);
				i++;
			}
			return (-1);
		}
		start = start + jump_step;
	}
	printf("Value found between indexes [%ld] and [%ld]\n", start, end);

	return (-1);
}
