#include "main.h"
/**
 *clear_bit - sets the value of a given bit to 0 at given index
 *@n: the number to be worked on
 *@index: the particular index of a bit to be cleared
 *Return: 1 if it succeeds, -1 if it fails
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
