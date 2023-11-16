#include "variadic_functions.h"
#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters
 * @n: number of parameters
 *
 * Return: 0 if n == 0 or sum of all parameters
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list numbers;
	unsigned int i;
	int result;

	va_start(numbers, n);
	for (i = 0; i < n; i++)
		result += va_arg(numbers, int);

	return (result);
}
