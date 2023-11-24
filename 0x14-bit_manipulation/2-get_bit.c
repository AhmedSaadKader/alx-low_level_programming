#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: unsigned long int to return the bit of
 * @index: the index to retrieve the index from
 *
 * Return: the value retrieved
*/

int get_bit(unsigned long int n, unsigned int index)
{
	int i;
	unsigned long int temp;
	temp = n >> index;
	i = (temp & 1);
	return (i);
}