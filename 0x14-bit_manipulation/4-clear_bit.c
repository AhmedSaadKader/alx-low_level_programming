#include "main.h"

/**
 * clear_bit - sets the value of a bit at a given index to 0
 * @n: the unsigned long int to manipulate its bits
 * @index: the index where the bit should be changed
 *
 * Return: 1 if success, or -1 if failure
*/

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > (sizeof(unsigned long int) * 8))
		return (-1);

	*n &= ~(1 << index);
	return (1);
}
