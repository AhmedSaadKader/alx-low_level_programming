#include "main.h"
#include <stdlib.h>

/**
 * _realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size: is the size in bytes of the allocated space for ptr
 * @new_size: is the new size in bytes of the new memory block
 *
 * Return: pointer to the newly allocated space
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *newptr, *oldptr;
	unsigned int i;

	oldptr = ptr;
	if (ptr == NULL)
	{
		newptr = malloc(new_size);
		return (newptr);
	}
	if (new_size == old_size)
		return (ptr);

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);
	for (i = 0; i < old_size && i < new_size; i++)
		newptr[i] = oldptr[i];
	free(ptr);
	return (newptr);
}
