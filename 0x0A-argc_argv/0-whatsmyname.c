#include <stdio.h>
#include "main.h"

/**
 * main - prints the program's name
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 to indicate success
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);

	return (0);
}
