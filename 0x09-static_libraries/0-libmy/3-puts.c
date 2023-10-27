#include "main.h"

/**
 * _puts - prints a string
 * @str: string to print
 */

void _puts(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		_putchar(str[len]);

	_putchar('\n');
}
