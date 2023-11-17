#include "lists.h"
#include <stdlib.h>

/**
 * free_list - free memory of linked list
 * @head: linked list to free
*/

void free_list(list_t *head)
{
	free(head->str);
	free(head);
}
