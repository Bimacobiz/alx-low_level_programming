#include "main.h"
/**
 *get_bit - will return the value of a bit at a particular
 *@n: the searched number
 *@index: the index of a particular bit
 *Return: the bit's value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_enum; /*bit_enum is the bit value*/

	if (index > 63)
		return (-1);

	bit_enum = (n >> index) & 1;

	return (bit_enum);
}
