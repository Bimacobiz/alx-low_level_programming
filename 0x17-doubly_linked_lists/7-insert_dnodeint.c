#include "lists.h"
/**
 *insert_dnodeint_at_index - a function that adds inserts a new node
 *at a given position
 *@h: the head of the list
 *@idx: index of the new node created
 *@n: new node value
 *Return: pointer to the new node and NULL incase of failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *updated_node;
	dlistint_t *list_head;
	unsigned int p;

	updated_node = NULL;
	if (idx == 0)
		updated_node = add_dnodeint(h, n);
	else
	{
		list_head = *h;
		p = 1;
		if (list_head != NULL)
			while (list_head->prev != NULL)
				list_head = list_head->prev;
		while (list_head != NULL)
		{
			if (p == idx)
			{
				if (list_head->next == NULL)
					updated_node = add_dnodeint_end(h, n);
				else
				{
					updated_node = malloc(sizeof(dlistint_t));
					if (updated_node != NULL)
					{
						updated_node->n = n;
						updated_node->next = list_head->next;
						updated_node->prev = list_head;
						list_head->next->prev = updated_node;
						list_head->next = updated_node;
					}
				}
				break;
			}
			list_head = list_head->next;
			p++;
		}
	}

	return (updated_node);
}
