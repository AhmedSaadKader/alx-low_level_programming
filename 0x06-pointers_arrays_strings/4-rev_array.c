#include "main.h"

/**
 * reverse_array - reverses the content of an array of integers
 * @a: array of integers
 * @n: number of elements of the array
 */

void reverse_array(int *a, int n)
{
	int i, x, temp;

	x = n - 1;

	for (i = 0; i < x / 2; i++)
	{
		temp = a[i];
		a[i] = a[x - i];
		a[x - i] = temp;
	}
}
