#include <stdio.h>

/**
 * main - Entry Point
 *
 * Return: Always 0
 */

int main(void)
{
	char lowerCh;
	char upperCh;

	for (lowerCh = 'a'; lowerCh <= 'z'; lowerCh++)
		putchar(lowerCh);

	for (upperCh = 'A'; upperCh <= 'Z'; upperCh++)
		putchar(upperCh);

	putchar('\n');

	return (0);
}
