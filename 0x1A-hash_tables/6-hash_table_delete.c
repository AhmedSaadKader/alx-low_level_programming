#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table
*/

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *current_node, *next_node;
	unsigned long int i = 0;

	if (ht->size == 0 || ht == NULL || ht->array == NULL)
		return;
	while (i < ht->size)
	{
		current_node = ht->array[i];
		while (current_node != NULL)
		{
			next_node = current_node->next;
			free(current_node->key);
			free(current_node->value);
			free(current_node);
			current_node = next_node;
		}
		i++;
	}
	free(ht->array);
	free(ht);
}
