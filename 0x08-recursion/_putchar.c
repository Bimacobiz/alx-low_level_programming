#include "main.h"                                                                                                                  
#include <unistd.h> 

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * On success, is returned 1.
 * On error, -1 is returned, and errnois then appropriately set.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
