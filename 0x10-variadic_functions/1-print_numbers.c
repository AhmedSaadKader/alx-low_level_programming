#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - print numbers
 * @separator: string to be printed between numbers
 * @n: number of integers passed to the function
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;

	va_start(numbers, n);
	for (i = 1; i <= n; i++)
	{
		if (separator == NULL || i == n)
		printf("%d", va_arg(numbers, int));
		else
		printf("%d%s", va_arg(numbers, int), separator);
	}
	va_end(numbers);
	printf("\n");
}
