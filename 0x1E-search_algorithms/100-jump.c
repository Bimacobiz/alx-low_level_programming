#include <math.h>
#include "search_algos.h"

/**
 * jump_search - uses a jump search to search a value in a sorted array.
 * @array: The array to be searched.
 * @size: Array length.
 * @value: The value to search.
 *
 * Return: The index of the value in the array, otherwise -1.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t step, c = 0, k = 0;

	if (!array)
		return (-1);
	step = (size_t)sqrt(size);
	while ((k < size) && (*(array + k) < value))
	{
		printf("Value checked array[%d] = [%d]\n", (int)k, *(array + k));
		c = k;
		d += step;
		if (c >= size)
			return (-1);
	}
	printf("Value found between indexes [%d] and [%d]\n", (int)c, (int)k);
	k = k >= size ? size - 1 : k;
	for (; (c <= k) && (*(array + c) <= value); c++)
	{
		printf("Value checked array[%d] = [%d]\n", (int)c, *(array + c));
		if (*(array + c) == value)
			return ((int)c);
	}
	return (-1);
}
