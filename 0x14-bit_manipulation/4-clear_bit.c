#include "main.h"
/**
 *clear_bit - a function that sets a bit's value to 0 at a particular index
 *@n: points to the number that should be changed
 *@index: the index of the bit that should be cleared
 *Return: 1 if it succeeds, -1 if it fails
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
