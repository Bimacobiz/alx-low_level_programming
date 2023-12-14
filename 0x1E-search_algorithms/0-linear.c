#include "search_algos.h"
/**
 * linear_search -  uses the linear search algorithm to search for a value in an
 * array of integers
 * @array: Array from which the int is searched.
 * @size: Array length.
 * @value: The value to look for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t a;

	for (a = 0; (a < size) && (array); a++)
	{
		if (*(array + a) == value)
		{
			printf("Value checked array[%d] = [%d]\n", (int)a, *(array + a));
			return (a);
		}
		else
		{
			printf("Value checked array[%d] = [%d]\n", (int)a, *(array + a));
		}
	}
	return (-1);
}
