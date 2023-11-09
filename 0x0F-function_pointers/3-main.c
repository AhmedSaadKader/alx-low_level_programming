#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	int (*calculation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	calculation = get_op_func(argv[2]);

	if (calculation == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if (argv[2][0] == '/' && atoi(argv[3]) == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", calculation(atoi(argv[1]), atoi(argv[3])));
	return (0);
}
