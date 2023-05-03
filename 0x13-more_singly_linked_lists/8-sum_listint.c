#include "lists.h"
/**
 *sum_listint - returns the sum of all the data (n) of a listint_t linked list
 *@head: pointer to the first node on the list
 *Return: Sum of the data
 */
int sum_listint(listint_t *head)
{
	listint_t *temp = head;
	int total = 0;

	while (temp != NULL)
	{
		total += temp->n;
		temp = temp->next;
	}
	return (total);
}
