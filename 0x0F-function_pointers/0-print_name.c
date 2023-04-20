#include "function_pointers.h"
#include <stdio.h>
/**
 *print_name - prints a name
 *@f: pointer to function
 *@name: string to add
 *Return: nothing (void)
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;


	f(name);
}
