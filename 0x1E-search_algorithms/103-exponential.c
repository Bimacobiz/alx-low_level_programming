#include "search_algos.h"

/**
 * print_array - Prints the contents of an array.
 * @array: the source of trhe array to be printed.
 * @l: The left index of the array.
 * @r: The right index of the array.
 */
void print_array(int *array, size_t l, size_t r)
{
	size_t b;

	if (array)
	{
		printf("Searching in array: ");
		for (b = l; b < l + (r - l + 1); b++)
			printf("%d%s", *(array + b), b < l + (r - l) ? ", " : "\n");
	}
}

/**
 * binary_search_index1 - uses binary search to search a value in
 * a sorted array using.
 * @array: The array to search in.
 * @l: The left index of the array.
 * @r: The right index of the array.
 * @value: The value being sought.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int binary_search_index1(int *array, size_t l, size_t r, int value)
{
	size_t k;

	if (!array)
		return (-1);
	print_array(array, l, r);
	k = l + ((r - l) / 2);
	if (l == r)
		return (*(array + k) == value ? (int)k : -1);
	if (value < *(array + k))
	{
		return (binary_search_index1(array, l, k - 1, value));
	}
	else if (value == *(array + k))
	{
		return ((int)k);
	}
	else
	{
		return (binary_search_index1(array, k + 1, r, value));
	}
}

/**
 * exponential_search - uses exponential search to searc a value
 * in a sorted array.
 * @array: The array to search.
 * @size: The array length.
 * @value: The value being sought.
 *
 * Return: The index of the value in the array, otherwise -1.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t low = 1, high = 2;

	if (!array || !size)
		return (-1);
	if (size < 2)
	{
		low = 0;
		high = 1;
	}
	else
	{
		while (low < size)
		{
			printf("Value checked array[%lu] = [%d]\n", low, array[low]);
			if (
				((array[low] <= value) && (array[high] >= value))
				|| ((low * 2) >= size)
				)
				break;
			low *= 2;
			high = high * 2 < size ? high * 2 : size - 1;
		}
	}
	printf("Value found between indexes [%lu] and [%lu]\n", low, high);
	return (binary_search_index1(array, low, high, value));
}
