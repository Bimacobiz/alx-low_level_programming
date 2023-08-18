#include "lists.h"
/**
 *dlistint_len - returns the number of elements that are contained
 *in a linked dlistint_t list.
 *@h: points to the head of the list
 *Return: Number of elements in the given list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int ele_no = 0;

	while (h != NULL)
	{
		ele_no++;
		h = h->next;
	}
	return (ele_no);
}
