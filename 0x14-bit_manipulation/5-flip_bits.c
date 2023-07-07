#include "main.h"
/**
 *flip_bits - returns the bits that should be flipped to
 *move from on number to the next
 *@n: the initial number
 *@m: the following number
 *Return: the number of bits that should be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int c, tally = 0;
	unsigned long int present;
	unsigned long int entire = n ^ m;

	for (c = 63; c >= 0; c--)
	{
		present = entire >> c;
		if (present & 1)
			tally++;
	}

	return (tally);
}
