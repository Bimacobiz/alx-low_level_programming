#include "lists.h"
/**
 *print_listint -  prints all the elements of a listint_t list.
 *@h: a pointer to the head of the linked list
 *Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	size_t nds = 0; /*nds is the number of nodes*/

	while (h)
	{
		printf("%d\n", h->n); /*n is a member of the listint_t structure*/
		nds++;
		h = h->next;
	}

	return (nds);
}
