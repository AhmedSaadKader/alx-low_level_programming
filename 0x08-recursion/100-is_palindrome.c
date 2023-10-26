#include "main.h"

/**
 * string_length - calculate string length recursively
 * @s: string to get length of
 *
 * Return: the length of the string
 */

int string_length(char *s)
{
	if (s[0] == '\0')
		return (0);

	return (1 + string_length(s + 1));
}

/**
 * compare_letters - compare letters in string to determine palindrome
 * @s: string to compare letters of
 * @start: first half of string
 * @end: last half of string
 *
 * Return: 1 if it is palindrome or 0 otherwise
 */

int compare_letters(char *s, int start, int end)
{
	if (start == end)
		return (1);

	if (s[start] == s[end])
		return (compare_letters(s, start + 1, end - 1));

	return (0);
}

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if string is a palindrome or 0 otherwise
 */

int is_palindrome(char *s)
{
	int sLength;

	sLength = string_length(s);

	return (compare_letters(s, 0, sLength));
}
