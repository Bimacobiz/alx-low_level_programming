#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list
 * @h: a double pointer to the head node of the linked list
 *
 * Return: the size of the list that was free’d
 */
size_t free_listint_safe(listint_t **h)
{
	size_t len = 0;
	int disp;
	/**
	 *disp is the difference between the address
	 *of the currnent node and the next node.
	 */
	listint_t *temp;

	if (!h || !*h)
		return (0);

	while (*h)
	{
		disp = *h - (*h)->next;
		if (disp > 0)
		{
			temp = (*h)->next;
			free(*h);
			*h = temp;
			len++;
		}
		else
		{
			free(*h);
			*h = NULL;
			len++;
			break;
		}
	}

	*h = NULL;

	return (len);
}
