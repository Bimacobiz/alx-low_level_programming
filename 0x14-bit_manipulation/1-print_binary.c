#include "main.h"
/**
 *print_binary - prints the binary form of a given integer
 *@n: the number whose binarybis required
 */
void print_binary(unsigned long int n)
{
	int z, instances = 0;
	unsigned long int currentValue;

	for (z = 63; z >= 0; z--)
	{
		currentValue = n >> z;

		if (currentValue & 1)
		{
			_putchar('1');
			instances++;
		}
		else if (instances)
			_putchar('0');
	}
	if (!instances)
		_putchar('0');
}
