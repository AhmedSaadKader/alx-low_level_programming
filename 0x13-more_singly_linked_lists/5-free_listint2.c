#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - frees a linked list and sets the head to NULL
 * @head: the linked list to free
*/

void free_listint2(listint_t **head)
{
	listint_t *temp, *current;

	if (head == NULL || *head == NULL)
	{
		return;
	}
	current = *head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}
