#include "main.h"

/**
 * get_endianness - checks the indanness
 *
 * Return: 0 if big endian, 1 if little endian
*/

int get_endianness(void)
{
	int i = 1;
	int *ptr = &i;

	return (*ptr);
}
