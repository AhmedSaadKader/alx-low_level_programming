#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table
 * @ht: the hash table
*/

void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i = 0, item_count = 0;



	if (ht == NULL || ht->size == 0 || ht->array == NULL)
		printf("{}\n");
	else
		printf("{");
	while (i < ht->size)
	{
		if (ht->array[i])
		{
			if (item_count > 0)
				printf(", ");
			printf("'%s': '%s'", ht->array[i]->key, ht->array[i]->value);
			item_count++;
		}
		i++;
	}
	printf("}\n");
}
