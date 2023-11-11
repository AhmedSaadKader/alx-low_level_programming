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
	/*char *letter;*/
	f_o format_list[] = {
		{"c", "char"},
		{"i", "integer"},
		{"f", "float"},
		{"s", "char *"}
	};
	for (i = 0; format[i] != '\0'; i++)
	{
		for(l = 0; l < 4; l++)
		{
		  if (format[i] == format_list[l].abb[0])
		    printf("%s\n", format_list[l].type);
		}
	}
	va_start(ap, format);
}
