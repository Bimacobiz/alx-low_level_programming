#include <unistd.h>
/**
 * _putchar - writes the character c to std output
 * @c: The character that should be printed
 *
 * Return: 1 on success.
 * On error, -1 will be returned, and errno is appropriately set.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
