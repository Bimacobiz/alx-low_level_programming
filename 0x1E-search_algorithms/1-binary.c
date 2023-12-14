#include "search_algos.h"

/**
 * print_array - Prints the contents of an array.
 * @array: where the array to print comes from.
 * @l: The left index of the array.
 * @r: The right index of the array.
 */
void print_array(int *array, size_t l, size_t r)
{
	size_t a;

	if (array)
	{
		printf("Searching in array: ");
		for (a = l; a < l + (r - l + 1); a++)
			printf("%d%s", *(array + a), a < l + (r - l) ? ", " : "\n");
	}
}

/**
 * binary_search_index - Searches a value in a sorted array using \
 * a binary search.
 * @array: The array to be searched.
 * @l: The left index of the array.
 * @r: The right index of the array.
 * @value: The value being sought.
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
		return (binary_search_index(array, l, k - 1, value));
	else if (value == *(array + k))
		return ((int)k);
	else
		return (binary_search_index(array, k + 1, r, value));
}

/**
 * binary_search - Searches a value in a sorted array using a binary search.
 * @array: The array to search in.
 * @size: The length of the array.
 * @value: The value to look for.
 *
 * Return: The index of the value in the array, otherwise -1.
 */
int binary_search(int *array, size_t size, int value)
{
	return (binary_search_index(array, 0, size - 1, value));
}
