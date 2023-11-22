#include "lists.h"

/**
 * sum_listint - sums all the data (n) of a listint_t linked list
 * @head: the linked list to sum
 *
 * Return: the sum of the data
*/

int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
