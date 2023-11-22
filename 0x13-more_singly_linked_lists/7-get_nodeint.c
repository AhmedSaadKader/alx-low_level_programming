#include "lists.h"

/**
 * get_nodeint_at_index - get the nth node of a linked list
 * @head: the linked list
 * @index: the index of the node
 *
 * Return: the node at the specified index or NULL if no nodes exist
*/

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head != NULL)
	{
		if (i == index)
			return (head);
		i++;
		head = head->next;
	}
	return (NULL);
}
