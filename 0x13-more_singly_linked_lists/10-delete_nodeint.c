#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index
 * @head: the linked list
 * @index: index to delete the node at
 *
 * Return: 1 if succeeded or -1 if failed
*/

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *current, *previous;

	if (*head == NULL)
		return (-1);

	current = *head;
	previous = NULL;
	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}
	while (current != NULL)
	{
		if (i == index)
		{
			previous->next = current->next;
			free(current);
			return (1);
		}
		i++;
		previous = current;
		current = current->next;
	}
	return (-1);
}
