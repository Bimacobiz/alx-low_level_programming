#include "main.h"
/**
 * _print_rev_recursion: Prints a string in reverse.
 * @s: The string that should be  printed.
 * @main(): demonstrates how the _print_rev_recursion() function works
 */
void _print_rev_recursion(char *s)

{	if (*s == '\0')

	return;

	_print_rev_recursion(s + 1);
	putchar(*s);
}

int main(void)/*demonstrates how the _print_rev_recursion() function works*/
{
	char str[] = "Hello, world!";

	_print_rev_recursion(str);
	putchar('\n');
	return (0);

}
