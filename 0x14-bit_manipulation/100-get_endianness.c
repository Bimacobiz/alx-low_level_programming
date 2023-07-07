#include "main.h"
/**
 *get_endianness - a function that checks endianness
 *Return: 0 if the endian is big and 1 if the endian is small
 */
int get_endianness(void)
{
	unsigned int c = 1;
	char *k = (char *) &c;

	return (*k);

}
