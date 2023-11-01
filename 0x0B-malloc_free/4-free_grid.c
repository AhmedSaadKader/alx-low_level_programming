#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2 dimensional grid
 * @grid: pointer to the 2d array
 * @height: number of rows in the grid
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		if (grid[i] != NULL)
		{
			free(grid[i]);
			grid[i] = NULL;
		}
	}

	free(grid);
}
