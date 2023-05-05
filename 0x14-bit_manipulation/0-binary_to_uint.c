#include "main.h"
#include <stddef.h>
/**
 *binary_to_uint - converts a binary number to an unsigned int
 *@b: a pointer to a string of 0 and 1 chars
 *Return: the converted number otherwise return 0
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal_num = 0;
	int a = 0;

	if (*b != (0 || 1))
		return 0;
	if (b == NULL)
		return 0;

	for (a=0;b[a];a++)
	{
		if (b[a] < '0' || b[a] > '1')
			return (0);
		decimal_num = 2 * decimal_num + (b[a] - '0');
	}

	return (decimal_num);
}
