#include "main.h"

/**
 * _puts - prints a string
 * @str: string to print
 */

void _puts(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		_putchar(str[len]);
}
    
