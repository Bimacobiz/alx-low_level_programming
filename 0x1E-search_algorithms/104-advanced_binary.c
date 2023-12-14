#include "search_algos.h"

/**
 * print_array - Prints the contents of an array.
 * @array: Tehe source of the array that should be printed.
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
 * binary_search_index - uses binary search to search a value
 * in a sorted array
 * @array: The array to search in.
 * @l: The left index of the array.
 * @r: The right index of the array.
 * @value: The value to look for.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int binary_search_index(int *array, size_t l, size_t r, int value)
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
		return (binary_search_index(array, l, k, value));
	}
	else if (value == *(array + k))
	{
		if ((k > 0) && (*(array + k - 1) == value))
		{
			return (binary_search_index(array, l, k, value));
		}
		return ((int)k);
	}
	else
	{
		return (binary_search_index(array, k + 1, r, value));
	}
}

/**
 * advanced_binary - uses binary search to search a value in
 * a sorted array.
 * @array: The array to search in.
 * @size: Array length.
 * @value: The value being sought.
 *
 * Return: The first index of the value in the array, otherwise -1.
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !size)
		return (-1);
	else if ((size == 1) && (*array == value))
		return (0);
	return (binary_search_index(array, 0, size - 1, value));
}
