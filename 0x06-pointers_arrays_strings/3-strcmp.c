#include "main.h"

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if s1 matches s2, negative if s1 is less than s2
 * positive if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	return (s1[0] - s2[0]);
}
