#include "lists.h"
/**
 *add_dnodeint - adds a new node at the start of the
 *in a linked dlistint_t list.
 *@head: double points to the head of the list
 *@n: elements added
 *Return: pointer to the new elements and NULL in
 *case of failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *updated_node;
	dlistint_t *h;

	updated_node = malloc(sizeof(dlistint_t));
	if (updated_node == NULL)
		return (NULL);

	updated_node->n = n;
	updated_node->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}

	updated_node->next = h;

	if (h != NULL)
		h->prev = updated_node;

	*head = updated_node;

	return (updated_node);
}
