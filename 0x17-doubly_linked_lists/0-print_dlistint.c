#include "lists.h"

/**
 * print_dlistint - a function that prints all elements included in a
 * dlistint_t list
 *
 * @h: points to the list's head
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	int element = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		element++;
		h = h->next;
	}

	return element;
}
