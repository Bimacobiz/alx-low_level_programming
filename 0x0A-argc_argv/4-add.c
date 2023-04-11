#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * check_num - finds out if a string has a digit
 * @str: array string
 * Return: 0 when program is successful
 */
int check_num(char *str)
{
	/*Declaration of variables*/
	unsigned int count;

	count = 0;
	while (count < strlen(str)) /*counting the string*/

	{
		if (!isdigit(str[count])) /*checking if there are digits in str*/
		{
			return (0);
		}

		count++;
	}
	return (1);
}

/**
 * main - Prints the name of the program
 * @argc: Count arguments
 * @argv: Arguments *
 * Return: 0 when program is successful
 */

int main(int argc, char *argv[])

{

	/*Declaration of variables*/
	int count;
	int str_to_int;
	int sum = 0;

	count = 1;
	while (count < argc) /*Goes through the whole array*/
	{
		if (check_num(argv[count]))

		{
			str_to_int = atoi(argv[count]); /*ATOI --> convert string to int*/
			sum += str_to_int;
		}

		/*Condition if one of the number contains symbols that are not digits*/
		else
		{
			printf("Error\n");
			return (1);
		}

		count++;
	}

	printf("%d\n", sum); /*print sum*/

	return (0);
}

