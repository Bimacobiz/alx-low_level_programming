#include "hash_tables.h"

/**
 * hash_djb2 - implements the the djb2 algorithm
 * @str: the string that should be hashed
 *
 * Return: 64 bits hash value
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash;
	int k;

	hash = 5381;
	while ((k = *str++))
	{
		hash = ((hash << 5) + hash) + k;
	}
	return (hash);
}
