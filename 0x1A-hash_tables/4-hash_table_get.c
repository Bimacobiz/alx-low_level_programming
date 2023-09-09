#include "hash_tables.h"
/**
 * hash_table_get - retrieves a value that is associated with a key
 * @ht: points to the available hash table
 * @key: the key that will be used in retrieving value
 *
 * Return: value or NULL in the case where there is no key
 */

char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int i = 0;
	hash_node_t  *store;

	if (!ht || !key || !*key)
		return (NULL);

	i = key_index((const unsigned char *)key, ht->size);
	store = ht->array[i];

	while (store)
	{
		if (!strcmp(key, store->key))
			return (store->value);
		store = store->next;
	}
	return (NULL);
}
