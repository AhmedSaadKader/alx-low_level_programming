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

	if (width == 0 || height == 0)
		return (NULL);

	grid = malloc(width * sizeof(int *));
	if (grid == NULL)
		return (NULL);

	for (i = 0; i < width; i++)
		for (n = 0; n < height; n++)
			grid[i][n] = 0;

	return (grid);
}
