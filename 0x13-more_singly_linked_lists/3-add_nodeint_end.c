#include "lists.h"
/**
 *add_nodeint_end - adds a new node at the end of a listint_t list
 *@head: a pointer to a pointer to the head of a singly linked list
 *@n: The data to be inserted into the new node
 *Return: the address of the new element, or NULL in case of failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_node;
	listint_t *temp = *head;

	new_node = malloc(sizeof(listint_t));

	if (!new_node)
		return (NULL);

	new_node->n = n;
	new_node->next = NULL;

	while (temp->next)
		temp = temp->next;
	temp->next = new_node;

	if (*head == NULL)
	{
		*head = new_node;
		return (new_node);
	}


	return (new_node);
}
