#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list
 * @head: the list to add new nodes to
 * @str: the string data contained in the new node
 *
 * Return: pointer to the list/new node
*/

list_t *add_node(list_t **head, const char *str)
{
	list_t *new;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);

	new->str = strdup(str);
	new->next = *head;
	*head = new;
	return (*head);
}
