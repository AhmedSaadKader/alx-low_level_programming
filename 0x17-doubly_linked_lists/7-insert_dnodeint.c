#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: doubly linked list
 * @idx: index to insert node at
 * @n: the number of the new node
 *
 * Return: the address of the new node or NULL if it failed
*/

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current;
	dlistint_t *new;
	unsigned int i = 0;

	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	current = *h;
	while ((i != idx) && (current != NULL))
	{
		current = current->next;
		i++;
	}
	new->next = current;
	new->prev = current->prev;
	current->prev->next = new;
	current->prev = new;
	return (new);
}
