#include "hash_tables.h"

/**
 * key_index - gives you the index of a key
 * @key: key to get the index of
 * @size: the size of the hash table
 *
 * Return: the index at which the key/value pair is stored
*/

unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int index;

	index = hash_djb2(key);
	if (index < size)
	{
		return (index);
	}
	return (-1);
}
