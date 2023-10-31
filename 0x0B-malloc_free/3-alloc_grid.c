#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array
 * of integers
 * @width: width of array
 * @height: height of array
 *
 * Return: pointer to the array
 */

int **alloc_grid(int width, int height)
{
	int i, n;
	int **grid;

	grid = malloc(width * sizeof(int *));
	for (i = 0; i < width; i++)
		grid[i] = malloc(height * sizeof(int *));

	for (i = 0; i < width; i++)
		for (n = 0; n < height; n++)
			grid[i][n] = 0;

	return (grid);
}
