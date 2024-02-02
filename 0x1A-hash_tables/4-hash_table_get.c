#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table
 * @key: the key to retrieve value of
 *
 * Return: the value
*/

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *current_node;
	unsigned long int index;

	if (ht == NULL || ht->array == NULL || key == NULL ||
		ht->size == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];
	if (!current_node)
		return (NULL);
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	return (current_node->value);
}
