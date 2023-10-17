#include "main.h"

/**
 * rev_string - reverses a string
 * @s: string to reverse
 */

void rev_string(char *s)
{
	int length, start, end;
	char temp;

	length = 0;
	while (s[length] != '\0')
		length++;

	end = length - 1;
	for (start = 0; start < end; start++, end--)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
	}
}
