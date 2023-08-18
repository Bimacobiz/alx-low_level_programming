#include "lists.h"
/**
 *sum_dlistint - the function returns the sum of all the data (n)
 *of a dlistint_t linked list
 *@head: points to the head of the list
 *Return: sum
 */
int sum_dlistint(dlistint_t *head)
{
	int result_sum;

	result_sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			result_sum += head->n;
			head = head->next;
		}
	}

	return (result_sum);
}
