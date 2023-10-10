#include "main.h"
#include <stdio.h>

/**
 * print_to_98 - prints all natural numbers from n to 98
 * @n: number to start printing from
 */

void print_to_98(int n)
{
if (n <= 98)
{
	for (i = n; i <= 98; i++)
		printf("%d, ", n++); 
	printf("%d\n", n);
}
else
{
	for (i = n; i >= 98; i--)
		printf("%d, ", n--);
	printf("%d\n", n);
}
}
