#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all the elements of a linked list
 * @h: the linked list to be printed
 *
 * Return: the number of nodes in the linked list
*/

size_t print_listint(const listint_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		count++;
	}

	return (count);
}
