#include "main.h"
/**
 *flip_bits -  returns the no. of bits that should be flipped
 *to get from one number to another.
 *@m: second integer
 *@n: first integer
 *Return: number of bits that should be changed
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int a, tally = 0;
	unsigned long int present;
	unsigned long int exclusive = n ^ m;

	for (a = 63; a >= 0; a--)
	{
		present = exclusive >> a;
		if (present & 1)
			tally++;
	}

	return (tally);

}
