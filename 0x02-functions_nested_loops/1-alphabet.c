#include "main.h"

/**
 * print_alphabet - print low case alphabets followed by a new line
 *
 * Return: Void
 */

void print_alphabet(void)
{
	char letter;

	for (letter = 'a'; letter <= 'z'; letter++)
	{
		_putchar(letter);
	}

	_putchar('\n');
}
