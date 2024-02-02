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
	unsigned long int index;

	if (ht == NULL || ht->array == NULL || key == NULL ||
		ht->size == 0)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	if (!ht->array[index])
		return (NULL);
	return (ht->array[index]->value);
}
