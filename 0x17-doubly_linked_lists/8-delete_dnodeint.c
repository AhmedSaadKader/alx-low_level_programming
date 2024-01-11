#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of double
 * linked list
 * @head: doubly linked list
 * @index: index to delete node at
 *
 * Return: 1 if succeeded or -1 if failed
*/

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *current;

	if (*head == NULL)
		return (-1);

	current = *head;
	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}
	while ((i < index) && (current != NULL))
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
		return (-1);
	current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
	return (1);
}
