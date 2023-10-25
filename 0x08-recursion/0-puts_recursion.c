#include "main.h"

/**
 * _puts_recursion - prints a string followed by a new line
 * @s: string to print
 */

void _puts_recursion(char *s)
{
	int i;

	i = 0;
	if (s[i] == '\0')
	{
		_putchar('\n');
	}
	_putchar(s[i]);
	s[i] = s[i+1];
	_puts_recursion(s);
}
