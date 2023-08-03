#include <stdio.h>
#include "main.h"
/**
*binary_to_uint - will convert a binary number into an unsigned integer
*@b: points to a string that has the binary number to be converted
*Return: the unsigned int that results from the conversion process
* otherwise return 0 if b is null or not binary.
*/
unsigned int binary_to_uint(const char *b)
{
	int q;
	unsigned int nu_dec = 0;

	if (b == NULL)
		return (0);

	for (q = 0; b[q]; q++)
	{
		if (b[q] < '0' || b[q] > '1')
			return (0);
		nu_dec = 2 * nu_dec + (b[q] - '0');
	}

	return (nu_dec);
}
