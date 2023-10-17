#include "main.h"

/**
 * puts2 - prints every other character of a string
 * starting with the first character
 * @str: string to print it characters
 */

void puts2(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i = i + 2)
		_putchar(str[i]);
	_putchar('\n');
}