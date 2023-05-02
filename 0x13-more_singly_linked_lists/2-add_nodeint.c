#include "lists.h"
/**
 *add_nodeint - adds a new node at the beginning of a listint_t list.
 *@head: a pointer to a pointer to the head of a singly linked list
 *@n: The data to be inserted into the new node
 *Return: the address of the new element, or NULL in case of failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);
	new_node->n = n;
	*head = new_node->next;
	*head = new_node;

	return (new_node);
}
