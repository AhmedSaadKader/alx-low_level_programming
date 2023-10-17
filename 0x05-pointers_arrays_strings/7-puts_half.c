#include "main.h"

/**
 * puts_half - prints half of a string
 * @str: string to print the half of the string of
 */

void puts_half(char *str)
{
	int len, n;

	len = 0;
	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
	{
		for (n = len / 2; n <= len - 1; n++)
			_putchar(str[n]);
		_putchar('\n');
	}
	else
	{
		for (n = (len - 1) / 2; n <= len - 1; n++)
			_putchar(str[n]);
		_putchar('\n');
	}
}
