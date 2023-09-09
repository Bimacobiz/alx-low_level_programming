#include "hash_tables.h"

/**
 * hash_table_set - will add an element to the hash table
 * @ht: points to the table
 * @key: the key to add the given element
 * @value: value to be added to the given element
 *
 * Return: 1 if successful, 0 if failure
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i = 0;
	char *copyvalue, *keycopy;
	hash_node_t  *bucket, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);

	copyvalue = strdup(value);
	if (!copyvalue)
		return (0);

	i = key_index((const unsigned char *)key, ht->size);
	bucket = ht->array[i];

	while (bucket)
	{
		if (!strcmp(key, bucket->key))
		{
			free(bucket->value);
			bucket->value = copyvalue;
			return (1);
		}
		bucket = bucket->next;
	}
	new_node = calloc(1, sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(copyvalue);
		return (0);
	}
	keycopy = strdup(key);
	if (!keycopy)
		return (0);
	new_node->key = keycopy;
	new_node->value = copyvalue;
	new_node->next = ht->array[i];
	ht->array[i] = new_node;
	return (1);
}
