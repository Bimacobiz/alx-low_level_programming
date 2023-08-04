#include "main.h"
/**
 *get_endianness - will check endianess
 *Return: 0 if big endian and 1 if small endian
 */
int get_endianness(void)
{
	unsigned int f = 1;
	char *m = (char *) &f;

	return (*m);

}
