#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table
*/

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0, item_count = 0;
	hash_node_t *current_node;

	if (ht == NULL || ht->size == 0 || ht->array == NULL)
		return;
	printf("{");
	while (i < ht->size)
	{
		current_node = ht->array[i];
		while (current_node != NULL)
		{
			if (item_count > 0)
				printf(", ");
			printf("'%s': '%s'", current_node->key, current_node->value);
			item_count++;
			current_node = current_node->next;
		}
		i++;
	}
	printf("}\n");
}
