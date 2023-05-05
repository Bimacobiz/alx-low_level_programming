#include "main.h"
/**
 *print_binary - prints the binary representation of a number
 *@n: the number that should be converted to binary and printed
 *Return: nothing (void)
 */
void print_binary(unsigned long int n)
{
	int a, tally = 0;
	unsigned long int present;

	for (a = 63; a >= 0; a--)
	{
		present = n >> a;
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
