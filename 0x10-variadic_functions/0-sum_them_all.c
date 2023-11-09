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
	int i;
	int result;

	va_start(ap, n);
	for (i = 0, i < n; i++)
		result += va_arg(ap, int);

	return (result);
}
