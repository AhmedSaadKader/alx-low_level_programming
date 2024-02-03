#include "hash_tables.h"

/**
 * shash_table_create - creates a hash table
 * @size: the size of the hash table
 *
 * Return: The hash table
*/

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->array = malloc(sizeof(shash_node_t) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
}

/**
 * shash_table_set - inserts a new node in the table
 * @ht: the hash table
 * @key: the key of the new node
 * @value: the value of the new node
 *
 * Return: 1 if successful, 0 otherwise
*/

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *current_node;
	unsigned long int index, i;

	if (ht == NULL || key == NULL || value == NULL ||
		ht->array == NULL || ht->size == 0)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];

	new_node = malloc(sizeof(shash_node_t));
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
	new_node->snext = NULL;
	new_node->sprev = NULL;

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
	}
	else
	{
		ht->stail->next = new_node;
		new_node->sprev = ht->stail;
		ht->stail = new_node;
	}
	if (current_node == NULL)
	{
		ht->array[index] = new_node;
		return (1);
	}
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			free(new_node->key);
			free(new_node->value);
			free(new_node);
			ht->array[index]->value = strdup(value);
			return (1);
		}
		current_node = current_node->next;
	}
	new_node->next = current_node;
	ht->array[index] = new_node;
	return (1);
}

/**
 * shash_table_get - retrieves a value from a hash table
 * @ht: the hash table
 * @key: the key of the node to retrieve
 *
 * Return: the value retrieves
*/

char *shash_table_get(const shash_table_t *ht, const char *key)
{

}

/**
 * shash_table_print - prints a hash table
 * @ht: the hash table
*/

void shash_table_print(const shash_table_t *ht)
{

}

/**
 * shash_table_print_rev - prints a hash table in reverse
 * @ht: the hash table
*/

void shash_table_print_rev(const shash_table_t *ht)
{

}

/**
 * shash_table_delete - deletes a hash table
 * @ht: the hash table
*/

void shash_table_delete(shash_table_t *ht)
{

}
