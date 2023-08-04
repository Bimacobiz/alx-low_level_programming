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
	int y, enumerations = 0;
	unsigned long int initial;
	unsigned long int all = n ^ m;

	for (y = 63; y >= 0; y--)
	{
		initial = all >> y;
		if (initial & 1)
			enumerations++;
	}

	return (enumerations);
}
