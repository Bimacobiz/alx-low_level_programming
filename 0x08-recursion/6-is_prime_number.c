#include "main.h"
int real_prime_number(int n, int i);
/**
 * _is_prime_number - returns 1 if the input integer is a prime number,
 * otherwise it returns 0.
 *@n: the number to identify 
 *Return: 1 if n is a prime number and zero if it is not a prime number
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (real_prime_number(n, n - 1));
}
/**
 *real_prime_number - indicates if n is a prime number or not 
 *@n: the number under evaluation
 @i: iterator 
 *Return: 1 if n is prime and 0 if otherwise
 */ 
int real_prime_number(int n, int i)
{
	if (i == 1)
		return (1);
	if (n % i == 0 && i > 0)
		return (0);
	return (real_prime_number(n, i - 1));
}
