#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a doubly
 * linked list
 * @head: doubly linked list
 * @index: the index to return the node at
 *
 * Return: the node
*/

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *current;

	current = head;
	while ((i != index) & (current != NULL))
	{
		current = current->next;
		i++;
	}

	return (current);
}
