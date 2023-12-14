#include <math.h>
#include "search_algos.h"

/**
 * get_n_next - Gets the nth node next to a given node.
 * @node: The initial node.
 * @n: Number of positions that are next to node.
 *
 * Return: The node n places next to the given node, \
 * otherwise the last node or NULL.
 */
listint_t *get_n_next(listint_t *node, size_t n)
{
	size_t b = 0;
	listint_t *res = NULL;

	res = node;
	for (b = 0; (b < n) && (res) && (res->next); b++)
		res = res->next;
	return (res);
}

/**
 * jump_list - Uses a jump search to seaech for a value
 * in a sorted linked list.
 * @list: The linked list from which the search should be done
 * @size: The length of the linked list
 * @value: Value being sought.
 *
 * Return: The node with the value in the linked list, otherwise NULL.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t step, c = 0, b = 0;
	listint_t *node, *next;

	if (!list)
		return (NULL);
	step = (size_t)sqrt(size);
	node = list;
	next = get_n_next(node, step);
	while (node)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)next->index, next->n);
		if ((next->n >= value) || (!next->next))
			break;
		node = next;
		next = get_n_next(node, step);
	}
	a = node->index;
	b = next->index;
	printf("Value found between indexes [%d] and [%d]\n", (int)a, (int)b);
	while (node)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}
	return (NULL);
}
