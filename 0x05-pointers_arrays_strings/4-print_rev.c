#include "main.h"

/**
 * print_rev - print a string in reverse
 * @s: string to be printed in reverse
 */

void print_rev(char *s)
{
	int len;
	int reverse;

	for (len = 0; s[len] != '\0'; len++)

	for (reverse = len - 1; reverse >= 0; reverse--)
		_putchar(s[reverse]);

	_putchar('\n');
}
