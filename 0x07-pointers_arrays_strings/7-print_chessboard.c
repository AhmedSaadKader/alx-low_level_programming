#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: board array
 */

void print_chessboard(char (*a)[8])
{
	int i, j, board_dimensions;

	board_dimensions = 8;

	for (i = 0; i < board_dimensions; i++)
	{
		for (j = 0; j < board_dimensions; j++)
		{
			_putchar(a[i][j]);
		}
		_putchar('\n');
	}
}
