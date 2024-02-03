#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key of the element
 * @value: the value of the element
 *
 * Return: 1 if succeeded, 0 otherwise
*/

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node, *current_node;
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL ||
		ht->array == NULL || ht->size == 0)
		return (0);
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);
	new_node->key = strdup(key);
	new_node->value = strdup(value);
	if (new_node->key == NULL || new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node->value);
		free(new_node);
		return (0);
	}
	new_node->next = NULL;
	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];
	if (current_node == NULL)
	{
		ht->array[index] = new_node;
		return (1);
	}
	if (strcmp(current_node->key, key) == 0)
	{
		free(current_node->value);
		current_node->value = strdup(value);
		if (current_node->value == NULL)
			return (0);
		return (1);
	}
	new_node->next = current_node;
	ht->array[index] = new_node;
	free(new_node->key);
	free(new_node->value);
	free(new_node);
	return (1);
}
