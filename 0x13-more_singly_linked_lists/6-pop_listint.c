#include "lists.h"

/**
 * pop_listint - remove head node from linked list
 * @head: linked list to remove head node from
 *
 * Return: the n integer of the popped head node
*/

int pop_listint(listint_t **head)
{
	int n;
	listint_t *current;

	if (*head == NULL)
		return (0);
	current = *head;
	n = current->n;
	*head = (*head)->next;
	free(current);
	return (n);
}
