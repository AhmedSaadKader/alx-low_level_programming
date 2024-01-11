#include "lists.h"

/**
 * sum_dlistint - returns the sum of all the data (n) of a
 * doubly linked list
 * @head: doubly linked list
 *
 * Return: the sum of all the data
*/

int sum_dlistint(dlistint_t *head)
{
	int result = 0;
	dlistint_t *current = head;

	while (current != NULL)
	{
		result += current->n;
		current = current->next;
	}
	return (result);
}
