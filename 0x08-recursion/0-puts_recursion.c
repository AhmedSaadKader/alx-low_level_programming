#include "main.h"

/**
 * _puts_recursion - prints a string followed by a new line
 * @s: string to print
 */

void _puts_recursion(char *s)
{
	if (s[0] == '\0')
	{
		_putchar('\n');
	}
	_putchar(s[0]);
	s[0] = s[1];

	_puts_recursion(s);
}
