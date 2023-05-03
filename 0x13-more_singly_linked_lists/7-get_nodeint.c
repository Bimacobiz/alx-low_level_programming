#include "lists.h"
/**
 *get_nodeint_at_index - returns the nth node of a listint_t linked list
 *@head: pointer to the first node on the list
 *@index: index of the node that we should retrieve from list
 *Return: Return the pointer to the node being sought
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	listint_t *temp = head;
	unsigned int count = 0;

	while (temp != NULL)
	{
		if (count == index)
			return (temp);
		count++;
		temp = temp->next;
	}
	return (NULL);
}
