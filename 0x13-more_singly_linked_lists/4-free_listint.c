#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - frees a linked list
 * @head: the linked list to be freed
*/

void free_listint(listint_t *head)
{
	listint_t *current, *temp;

	current = head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
}
