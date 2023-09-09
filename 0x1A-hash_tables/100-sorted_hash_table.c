#include "hash_tables.h"

/**
 * sorted_list - will add a new node in sorted
 * @ht: points to the sorted table
 * @new_node: node to be inserted
 *
 */
void sorted_list(shash_table_t *ht, shash_node_t *new_node)
{
	shash_node_t *sstore = ht->shead;

	if (sstore == NULL)
	{
		ht->shead = ht->stail = new_node;
		new_node->snext = new_node->sprev = NULL;
		return;
	}
	do {
		if (strcmp(new_node->key, sstore->key) < 0)
		{
			new_node->snext = sstore;
			new_node->sprev = sstore->sprev;

			if (!sstore->sprev)
				ht->shead = new_node;
			else
				sstore->sprev->snext = new_node;
			sstore->sprev = new_node;
			return;
		}
		sstore = sstore->snext;
	} while (sstore);
	new_node->sprev = ht->stail;
	new_node->snext = ht->stail->snext;
	ht->stail->snext = new_node;
	ht->stail = new_node;
}

/**
 * shash_table_create - creates a sorted hash tables
 * @size: hash table size
 *
 * Return: points to the table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *hash_t;

	if (size == 0)
		return (NULL);

	hash_t = calloc(1, sizeof(shash_table_t));
	if (hash_t == NULL)
		return (NULL);

	hash_t->size = size;
	hash_t->array = calloc(size, sizeof(shash_node_t *));
	if (hash_t->array == NULL)
	{
		free(hash_t);
		return (NULL);
	}
	return (hash_t);
}

/**
 * shash_table_set - adds an elemwent to the sorted hash table
 * @ht: points to the sorted hash table
 * @key: key to be added to element
 * @value: value to add to element
 *
 * Return: 1 is successful, 0 if failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i = 0;
	char *copyvalue, *keycopy;
	shash_node_t  *store, *new_node;

	if (!ht || !key || !*key || !value)
		return (0);
	copyvalue = strdup(value);
	if (!copyvalue)
		return (0);
	i = key_index((const unsigned char *)key, ht->size);
	store = ht->array[i];

	while (store)
	{
		if (!strcmp(key, store->key))
		{
			free(store->value);
			store->value = copyvalue;
			return (1);
		}
		store = store->next;
	}
	new_node = calloc(1, sizeof(shash_node_t));
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
	sorted_list(ht, new_node);
	return (1);
}
/**
 * shash_table_get - retrieves a value that is associated with a key
 * @ht: points to hash table
 * @key: key thst retrieves value
 *
 * Return: value or NULL if key fails to exit.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int i = 0;
	shash_node_t  *store;

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

/**
 * shash_table_print - prints the value
 * @ht: points to hash table
 *
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *store;
	int not_fin = 0;

	if (!ht)
		return;
	store = ht->shead;
	printf("{");
	while (store)
	{
		if (not_fin)
			printf(", ");
		printf("'%s': '%s'", store->key, store->value);
		not_fin = 1;
		store = store->snext;
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - prints the value of the table in reverse
 * @ht: points to hash table
 *
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *store;
	int not_fin = 0;

	if (!ht)
		return;
	store = ht->stail;
	printf("{");
	while (store)
	{
		if (not_fin)
			printf(", ");
		printf("'%s': '%s'", store->key, store->value);
		not_fin = 1;
		store = store->sprev;
	}
	printf("}\n");
}
/**
 * shash_table_delete - deletes hash table and all nodes
 * @ht: pointer to hash table
 *
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *store, *aux_del;
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
