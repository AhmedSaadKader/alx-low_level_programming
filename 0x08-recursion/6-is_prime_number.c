#include "main.h"

/**
 * find_prime - calculates prime recursively
 * @a: number to divide by
 * @n: number to check if prime
 *
 * Return: 1 if prime number or 0 otherwise
 */

int find_prime(int a, int n)
{
	if (n <= 1)
		return (0);
	if (n <= 3)
		return (1);
	if (n % 2 == 0 || n % 3 == 0)
		return (0);
	if (a * a > n)
		return (1);
	if (n % a == 0 || n % (a + 2) == 0)
		return (0);
	return (find_prime(a + 6, n));
}

/**
 * is_prime_number - checks if prime number
 * @n: number to check
 *
 * Return: 1 if prime number
 */

int is_prime_number(int n)
{
	int x;

	x = find_prime(5, n);
	return (x);
}
