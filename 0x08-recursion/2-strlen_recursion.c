#include "main.h"
/**
 * strlen_recursion - returns the length of a string
 * @s: a pointer to the string to be printed
 * @*s: differences the pointer
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
	{
		return 0;
	}
	_strlen_recursion(s + 1);
	_putchar(*s);
	return 0;
}
