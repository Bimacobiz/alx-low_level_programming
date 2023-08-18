#include "lists.h"

int delete_dnodeint_at_index(dlistint_t **head, unsigned int index);
/**
 *delete_dnodeint_at_index - a function that adds inserts a new node
 *at a given position
 *@head: the head of the list
 *@index: index of the new node created
 *@n: new node value
 *Return: 1 if successful,-1 if failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *buf1;
	dlistint_t *buf2;
	unsigned int p;

	buf1 = *head;

	if (buf1 != NULL)
		while (buf1->prev != NULL)
			buf1 = buf1->prev;

	p = 0;

	while (buf1 != NULL)
	{
		if (p == index)
		{
			if (p == 0)
			{
				*head = buf1->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				buf2->next = buf1->next;

				if (buf1->next != NULL)
					buf1->next->prev = buf2;
			}

			free(buf1);
			return (1);
		}
		buf2 = buf1;
		buf1 = buf1->next;
		p++;
	}

	return (-1);
}
