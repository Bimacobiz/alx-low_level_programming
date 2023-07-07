#include "main.h"
/**
 *get_bit - a function that returns a bit's value at a given index
 *@n: the number that should be searched
 *@index: the index of the given bit
 *Return: the bit's value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bvalue; /*bvalue is the value of the bit*/

	if (index > 63)
		return (-1);

	bvalue = (n >> index) & 1;

	return (bvalue);
}
