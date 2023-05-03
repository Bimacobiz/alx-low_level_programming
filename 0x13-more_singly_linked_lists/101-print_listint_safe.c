#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a linked list that is looped.
 * @head: a pointer to the head node of the linked list.
 *
 * Return: 0 if the list is not looped otherwise
 * Return the number of nodes printed.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *t, *f;
	size_t nds = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	f = (head->next)->next;
	t = head->next;


	while (f)
	{
		if (t == f)
		{
			t = head;
			while (t != f)
			{
				nds++;
				t = t->next;
				f = f->next;
			}

			t = t->next;
			while (t != f)
			{
				nds++;
				t = t->next;
			}

			return (nds);
		}

		t = t->next;
		f = (f->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - prints a listint_t linked list
 * @head:  pointer to the head node of the linked list.
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nds, index = 0;

	nds = looped_listint_len(head);

	if (nds == 0)
	{
		for (; head != NULL; nds++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < nds; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (nds);
}
