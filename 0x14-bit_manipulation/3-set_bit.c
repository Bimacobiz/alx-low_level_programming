#include "main.h"
/**
 *set_bit - sets the value of a bit to be one at a given index
 *@n: points to the number that should be changed
 *@index: index of the bit that should be set to 1
 *Return: 1 if it succeeds, -1 if it fails
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
