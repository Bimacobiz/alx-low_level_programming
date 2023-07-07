#include "main.h"
/**
 *print_binary - a function that prints the binary format of an integer
 *@n: the number whhose binary form should be presented
 */
void print_binary(unsigned long int n)
{
	int c, tally = 0;
	unsigned long int present;

	for (c = 63; c >= 0; c--)
	{
		present = n >> c;

		if (present & 1)
		{
			_putchar('1');
			tally++;
		}
		else if (tally)
			_putchar('0');
	}
	if (!tally)
		_putchar('0');
}
