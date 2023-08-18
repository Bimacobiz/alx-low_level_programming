#include "lists.h"
/**
 *get_dnodeint_at_index - the function returns the nth node
 *of a dlistint_t linked list
 *@head: points to the head of the list
 *@index: the index yo search for in the node and starts at 0
 *Return: nothing
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int node_size;
	dlistint_t *tmp;

	node_size = 0;
	if (head == NULL)
		return (NULL);

	tmp = head;
	while (tmp)
	{
		if (index == node_size)
			return (tmp);
		node_size++;
		tmp = tmp->next;
	}
	return (NULL);
}
