#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square
 * matrix of integers
 * @a: square two dimensional array
 * @size: size of the square
 */

void print_diagsums(int *a, int size)
{
	int i, n;

	for (i = 0, n = size; i < (size*size); i++, --n)
	{
	  printf("%i", a[i]);
	}
}
