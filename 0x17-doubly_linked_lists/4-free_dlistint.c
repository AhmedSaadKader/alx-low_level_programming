#include "lists.h"

/**
 * free_dlistint - frees a doubly linked list
 * @head: doubly linked list
*/

void free_dlistint(dlistint_t *head)
{
	dlistint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
