#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a doubly
 * linked list
 * @head: doubly linked list
 * @n: the data of the newly created node
 *
 * Return: the address of the new element
*/

dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new;
	dlistint_t *current;

	current = *head;
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (*head == NULL)
	{
		new->prev = NULL;
		*head = new;
		return (new);
	}

	while (current->next != NULL)
	{
		current = current->next;
	}
	new->prev = current;
	current->next = new;
	return (new);
}
