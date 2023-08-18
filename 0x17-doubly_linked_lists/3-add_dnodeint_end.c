#include "lists.h"
/**
 *add_dnodeint_end - adds a new node at the end of the
 *in a linked dlistint_t list.
 *@head: double points to the head of the list
 *@n: elements added
 *Return: pointer to the new elements and NULL in
 *case of failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h;
	dlistint_t *updated_node;

	updated_node = malloc(sizeof(dlistint_t));
	if (updated_node == NULL)
		return (NULL);

	updated_node->n = n;
	updated_node->next = NULL;

	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = updated_node;
	}
	else
	{
		*head = updated_node;
	}

	updated_node->prev = h;

	return (updated_node);
}
