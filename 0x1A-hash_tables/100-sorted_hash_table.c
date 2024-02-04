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
	ht->array = calloc(sizeof(shash_node_t *), size);
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
	return (ht);
}

/**
 * shash_node_create - creates a new node
 * @key: the key of the new node
 * @value: the value of the new node
 *
 * Return: the new node
*/

shash_node_t *shash_node_create(const char *key, const char *value)
{
	shash_node_t *new_node;

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
		return (NULL);
	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (NULL);
	}
	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	new_node->snext = NULL;
	new_node->sprev = NULL;
	return (new_node);
}

/**
 * add_node_to_sorted_list - adds the node to the sorted list
 * @ht: the hash table
 * @new_node: the node to add
*/

void add_node_to_sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *sorted_list;
	int key_order;

	if (ht->shead == NULL)
	{
		ht->shead = new_node;
		ht->stail = new_node;
		return;
	}
	sorted_list = ht->shead;
	while (sorted_list != NULL)
	{
		key_order = strcmp(sorted_list->key, new_node->key);
		if (key_order > 0)
		{
			new_node->snext = sorted_list;
			new_node->sprev = sorted_list->sprev;
			sorted_list->sprev = new_node;
			if (sorted_list->sprev != NULL)
				sorted_list->sprev->snext = new_node;
			else
				ht->shead = new_node;
			return;
		}
		sorted_list = sorted_list->snext;
	}
	new_node->sprev = ht->stail;
	ht->stail->snext = new_node;
	ht->stail = new_node;
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
	unsigned long int index;

	if (ht == NULL || key == NULL || value == NULL ||
		ht->array == NULL || ht->size == 0)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
		{
			free(current_node->value);
			current_node->value = strdup(value);
			if (current_node->value == NULL)
				return (0);
			return (1);
		}
		current_node = current_node->next;
	}
	new_node = shash_node_create(key, value);
	if (new_node == NULL)
		return (0);
	new_node->next = current_node;
	ht->array[index] = new_node;
	add_node_to_sorted_list(ht, new_node);
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
	unsigned long int index;
	shash_node_t *current_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
		key == NULL)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	current_node = ht->array[index];
	if (!current_node)
		return (NULL);
	while (current_node != NULL)
	{
		if (strcmp(current_node->key, key) == 0)
			return (current_node->value);
		current_node = current_node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a hash table
 * @ht: the hash table
*/

void shash_table_print(const shash_table_t *ht)
{
	unsigned long int i = 0;
	shash_node_t *current_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	current_node = ht->shead;
	printf("{");
	while (current_node != NULL)
	{
		if (i == 1)
			printf(", ");
		printf("%s: %s", current_node->key, current_node->value);
		i = 1;
		current_node = current_node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a hash table in reverse
 * @ht: the hash table
*/

void shash_table_print_rev(const shash_table_t *ht)
{
	unsigned long int i = 0;
	shash_node_t *current_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	current_node = ht->stail;
	printf("{");
	while (current_node != NULL)
	{
		if (i == 1)
			printf(", ");
		printf("%s: %s", current_node->key, current_node->value);
		i = 1;
		current_node = current_node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a hash table
 * @ht: the hash table
*/

void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *current_node, *next_node;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;

	current_node = ht->shead;
	while (current_node != NULL)
	{
		next_node = current_node->snext;
		free(current_node->key);
		free(current_node->value);
		free(current_node);
		current_node = next_node;
	}

	free(ht->array);
	ht->shead = NULL;
	ht->stail = NULL;
	free(ht);
}
