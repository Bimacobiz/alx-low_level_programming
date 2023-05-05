#include "main.h"
/**
 *get_endianness -  checks the endianness 
 *Return: 0 if the endian is big and i if it is small
 */
int get_endianness(void)
{
	unsigned int a = 1;
	char *h = (char *) &a;

	return (*h);
}
