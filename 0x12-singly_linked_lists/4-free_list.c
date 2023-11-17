#include "lists.h"
#include <stdlib.h>

/**
 * free_list - free memory of linked list
 * @head: linked list to free
*/

void free_list(list_t *head)
{
	list_t *current, *temp;

	current = head;
	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp->str);
		free(temp);
	}
}
