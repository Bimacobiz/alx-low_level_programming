#include "lists.h"
/**
 *listint_len - returns the number of elements in a linked listint_t list.
 *@h: a pointer to the head node
 *Return: the number of elements in a linked listint_t list.
 */
size_t listint_len(const listint_t *h)
{
	size_t nds = 0; /*nds is the number of nodes (elements)*/

	while (h)
	{
		nds++;
		h = h->next;
	}

	return (nds);
}
