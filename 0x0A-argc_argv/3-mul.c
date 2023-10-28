#include <stdio.h>
#include <stdlib.h>

/**
 * main - multiplies two numbers
 * @argc: number of arguments
 * @argv: array of argument
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	int i;

	if (argc != 3)
	{
		printf("Error");
		return (1);
	}
	i = 1;
	printf("%d\n", atoi(argv[i]) * atoi(argv[i + 1]));
	return (0);
}
