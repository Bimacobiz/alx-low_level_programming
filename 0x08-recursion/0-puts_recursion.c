#include "main.h"
/**
 * puts_recursion - a function that prints a string followed by a new line 
 * @*s differences the pointer and snd is used in accessing the character at the current position in the string
 *
 */
void _puts_recursion(char *s) {
	if (*s == '\0') {
		putchar('\n');
		return;
	}
	putchar(*s);
	_puts_recursion(s+1);
}
