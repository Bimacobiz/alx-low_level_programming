#include "hash_tables.h"

/**
 * key_index - gives an index of a given key
 * @key: string to be hashed
 * @size: table size
 *
 * Return: 'key's' index using djb2
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
