#include "lists.h"
/**
 *free_listint - frees a listint_t list
 *@head: pointer to the first node in the linked list to free
 *Return: nothing
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head)
	{
		if (head == NULL)
			return;
		temp = head->next;
		free_listint(temp);
		free(head);
	}
}
