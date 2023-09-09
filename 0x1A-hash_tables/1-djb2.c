#include "hash_tables.h"

/**
 * hash_djb2 - implements the the djb2 algorithm
 * @str: the string that should be hashed
 *
 * Return: 64 bits hash value
 */

unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int alg_hash;
	int k;

	hash = 5381;
	while ((k = *str++))
	{
		hash = ((alg_hash << 5) + alg_hash) + k;
	}
	return (alg_hash);
}
