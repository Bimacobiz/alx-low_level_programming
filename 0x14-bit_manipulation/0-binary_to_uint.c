#include <stdio.h>
#include "main.h"
/**
*binary_to_uint - converts a binary number to an unsigned int.
*@b: a pointer to a string that contains 0 and 1 chars
*Return: the result of the conversion, otherwise return 0
*if b does not contain 0 and a or is NULL.
*/
unsigned int binary_to_uint(const char *b)
{
	int z;
	unsigned int decnu = 0;

	if (b == NULL)
		return (0);

	for (z = 0; b[z]; z++)
	{
		if (b[z] < '0' || b[z] > '1')
			return (0);
		decnu = 2 * decnu + (b[z] - '0');
	}

	return (decnu);
}
