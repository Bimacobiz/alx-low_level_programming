#include "main.h"
#include <stdlib.h>
/**
 *create_array - returns a pointer to a newly allocated space
 *in memory, which contains a copy of the string given as a parameter.
 *@c: char to assign
 * @size: size of array
 * Return: pointer to the array and null if the program fails
 */
char *create_array(unsigned int size, char c)

{

	char *str;

	unsigned int i;



	str = malloc(sizeof(char) * size);

	if (size == 0 || str == NULL)

		return (NULL);



	for (i = 0; i < size; i++)

		str[i] = c;

	return (str);

}
