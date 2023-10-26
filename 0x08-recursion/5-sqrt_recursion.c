#include "main.h"

/**
 * find_sqrt - makes the calculations
 * @a: candidate number
 * @b: target number
 *
 * Return: correct candidate number or -1
 */

int find_sqrt(int a, int b)
{
	if (a * a == b)
		return (a);
	if (a * a > b)
		return (-1);
	return (find_sqrt(a + 1, b));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to find the square root of
 *
 * Return: square root
 */

int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (0);
	else
		return (find_sqrt(1, n));
}
