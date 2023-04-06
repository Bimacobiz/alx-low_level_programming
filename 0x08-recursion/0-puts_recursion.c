#include "main.h"
/**
 *_puts_recursion - a function that prints a string followed by a new line
 *@*s: differences the pointer
 *@s: a pointer to the string to be printed
 *Return: void
 */
void _puts_recursion(char *s)
{
	if (*s == '\0')
	{
		putchar('\n');
		return;
	}
	putchar(*s);
	_puts_recursion(s + 1);
}
