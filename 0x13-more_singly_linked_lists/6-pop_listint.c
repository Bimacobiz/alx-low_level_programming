#include "lists.h"
/**
 *pop_listint - deletes the head node of a listint_t linked list,
 *and returns the head node’s data (n)
 *@head: pointer to the pointer of the first node
 *in the linked list whose head node should be deleted
 *Return: Return head node's data
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int value;

	if (*head == NULL)
	{
		return (0);
	}

	temp = *head;
	value = temp->n;
	*head = temp->next;
	free(temp);

	return (value);
}
