#include <stdio.h>
#include <ctype.h>

/**
 * main - adds positive numbers
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 if success, 1 if error
 */

int main(int argc, char *argv)
{
	int i, total;

	total = 0;
	for (i = 1; i < argc; i++)
	{
		if (!isdigit(argv[i]))
		{
			printf("Error");
			return (1);
		}
		total += total + argv[i];
	}
	printf("%d", total);
	return (0);
		  
}
