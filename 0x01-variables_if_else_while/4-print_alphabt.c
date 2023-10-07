#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 1
 */

int main(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
		{
		if (ch != 'e' && ch != 'q')
			putchar(ch);
		}

	 putchar('\n');
}
