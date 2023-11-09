#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_strings - prints strings
 * @separator: the string to be printed between strings
 * @n: number of strings passed to the function
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings;
	unsigned int i;
	char *str;

	va_start(strings, n);
	for (i = 1; i <= n; i++)
	{
		str = va_arg(strings, char*);
		if (str == NULL)
			str = "(nil)";
		if (separator == NULL || i == n)
			printf("%s", str);
		else
			printf("%s%s", str, separator);
	}
	    
}
