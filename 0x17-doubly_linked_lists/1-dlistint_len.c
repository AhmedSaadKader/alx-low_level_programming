#include "lists.h"

/**
 * dlistint_len - returns the number of elements in doubly linked list
 * @h: doubly linked list
 *
 * Return: the number of elementsn
*/

size_t dlistint_len(const dlistint_t *h)
{
	int i = 0;

	while (h != NULL)
	{
		h = h->next;
		i++;
	}
	return (i);
}
