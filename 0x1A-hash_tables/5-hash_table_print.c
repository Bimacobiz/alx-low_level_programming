#include "hash_tables.h"

/**
 * hash_table_print - prints the hash table
 * @ht: points to hash table
 *
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int a = 0;
	hash_node_t  *store;
	int not_fin = 0;

	if (!ht)
		return;

	printf("{");
	for (a = 0; a < ht->size; a++)
	{
		store = ht->array[a];
		while (store)
		{
			if (not_fin)
				printf(", ");
			printf("'%s': '%s'", store->key, store->value);
			not_fin = 1;
			store = store->next;
		}
	}
	printf("}\n");
}
