#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - adds a new node at the end of a list
 * @head: the list to add the new node to
 * @str: string of the new node to add
 *
 * Return: pointer to the address of the new element or NULL if failed
*/

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *current;
	int str_len;

	str_len = strlen(str);
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	new->len = str_len;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current->next != NULL)
			current = current->next;
		current->next = new;
	}
	return (*head);
}
