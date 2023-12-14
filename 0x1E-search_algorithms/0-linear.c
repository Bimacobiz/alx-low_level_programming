#include "search_algos.h"
/**
 * linear_search -  uses the linear search algorithm to search for
 * a value in ani array of integers
 * @array: Array from which the int is searched.
 * @size: Array length.
 * @value: The value to look for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int linear_search(int *array, size_t size, int value)
{
	size_t p;

	for (p = 0; (p < size) && (array); p++)
	{
		if (*(array + p) == value)
		{
			printf("Value checked array[%d] = [%d]\n", (int)p, *(array + p));
			return (p);
		}
		else
		{
			printf("Value checked array[%d] = [%d]\n", (int)p, *(array + p));
		}
	}
	return (-1);
}
