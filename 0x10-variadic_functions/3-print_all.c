#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */

void print_all(const char * const format, ...)
{
	va_list ap;
	int i, l;
	f_o format_list[] = {
		{"c", print_char},
		{"i", print_int},
		{"f", print_float},
		{"s", print_char},
		{NULL, NULL}
	};

	va_start(ap, format);
	i = 0;
	while (format[i] != '\0')
	{
		l = 0;
		while (format_list[l].abb != NULL)
		{
			if (format[i] == format_list[l].abb[0])
			{
				format_list[l].type_check(ap);
				if (format[i + 1] != '\0')
					printf(", ");
					break;
			}
			l++;
		}
		i++;
	}
	printf("\n");
	va_end(ap);
}

/**
 * print_char - prints char
 * @args: variable argument
*/

void print_char(va_list args)
{
	printf("%c", va_arg(args, int));
}

/**
 * print_int - prints int
 * @args: variable argument
*/

void print_int(va_list args)
{
	printf("%d", va_arg(args, int));
}

/**
 * print_float - prints float
 * @args: variable argument
*/

void print_float(va_list args)
{
	printf("%f", va_arg(args, double));
}

/**
 * print_string - prints string
 * @args: variable argument
*/

void print_str(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(nil)";
	printf("%s", str);
}
