#include "main.h"

/**
 * flip_bits - returns the number of bits you would need to flip
 * to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: the number of bits
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int number_of_bits = 0, i = 0;

	while (i < (sizeof(unsigned long int) * 8))
	{
		number_of_bits += ((n >> i) ^ (m >> i)) & 1;
		i++;
	}
	return (number_of_bits);
}
