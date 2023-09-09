#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: points to the hash table
 *
 */

void hash_table_delete(hash_table_t *ht)
{
	hash_node_t *store, *aux_del;
	unsigned long int a = 0;

	if (!ht)
		return;

	for (a = 0; a < ht->size; a++)
	{
		store = ht->array[a];
		while (store)
		{
			aux_del = store;
			store = store->next;
			if (aux_del->key)
				free(aux_del->key);
			if (aux_del->value)
				free(aux_del->value);
			free(aux_del);
		}
	}
	free(ht->array);
	free(ht);
}
