#include "main.h"
#include <stdlib.h>

/**
 * _calloc - allocates memory for an array
 * @nmemb: number of elements in array
 * @size: size of bytes of element in array
 *
 * Return: pointer to the allocated memory
 * or NULL if malloc fails or if nmemb or size is 0
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *memalloc;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	memalloc = malloc(nmemb * size);
	if (memalloc == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		memalloc[i] = 0;
	return (memalloc);
}
