#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 * @b: size of memory
 *
 * Return: the allocated memory or
 * if malloc fails it should cause normal process
 * termination with a status value of 98
 */

void *malloc_checked(unsigned int b)
{
	void *mem;

	mem = malloc(b);
	if (mem == NULL)
		exit(98);
	return (mem);
}
