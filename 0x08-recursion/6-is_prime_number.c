#include "holberton.h"

/**
 * check - checks to see if number is prime
 * @a:int
 * @n:int
 * Return:int
 */
int check(int a, int n)
{
	if (n < 2 || n % a == 0)
		return (0);
	else if (a > n / 2)
		return (1);
	else
		return (check(a + 1, n));
}

/**
 * is_prime_number - states if number is prime
 * @n:int
 * Return:int
 */

int is_prime_number(int n)
{
	if (n == 2)
		return (1);
	return (check(2, n));
}
