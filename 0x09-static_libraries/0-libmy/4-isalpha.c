#include "main.h"

/**
 * _isalpha - checks for alphabetic character
 * @c: char to be checked
 *
 * Return: 1 if c is a letter, 0 if otherwise
 */

int _isalpha(int c)
{
	if (c >= 'A' && c <= 'z')
		return (1);
	else
		return (0);
}
