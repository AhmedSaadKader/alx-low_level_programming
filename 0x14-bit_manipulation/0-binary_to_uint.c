#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointing to a string of 0 and 1 chars
 *
 * Return: the converted number or 0 if
 * there is one or more chars in the string that is not 0 or 1
 * b is NULL
*/

unsigned int binary_to_uint(const char *b)
{
	unsigned int i = 0, converted = 0;

	if (b == NULL)
		return (0);
	while (b[i] != '\0')
	{
		if (b[i] != '1' && b[i] != '0')
			return (0);
		converted = (converted << 1) + (b[i] - '0');
		_putchar(converted);
		i++;
	}
	return (converted);
}
