#include <stdio.h>
#include "main.h"
/**
 * main - prints the number of arguments that passs through the program
 * @argv: array of arguments
 * @argc: number of arguments
 * Return:0 to indicate the success of tethe program
 */
int main(int argc, char *argv[])
{
	(void) argv; /*Ignore argv*/
	printf("%d\n", argc - 1);

	return (0);
}
