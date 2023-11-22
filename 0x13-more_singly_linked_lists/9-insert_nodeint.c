#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: linked list
 * @idx: index to put the node at
 * @n: the data of the new node
 *
 * Return: the address of the new node or NULL if failed
*/

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *new_node, *current, *previous;

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;
	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}
	current = *head;
	previous = NULL;
	while (current != NULL)
	{
		if (i == idx)
		{
			if (previous != NULL)
			{
				previous->next = new_node;
				new_node->next = current;
				return (new_node);
			}
		}
		i++;
		previous = current;
		current = current->next;
	}
	if (i == idx)
	{
		previous->next = new_node;
		return (new_node);
	}
	free(new_node);
	return (NULL);
}
