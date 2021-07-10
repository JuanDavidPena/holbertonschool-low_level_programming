#include "holberton.h"

/**
 * check - checks for the square root
 * @raiz:int
 * @n:int
 *
 * Return: int
 */

int check(int raiz, int n)
{
	if (raiz * raiz == n)
		return (a);
	if (raiz * raiz > n)
		return (-1);
	return (check(raiz + 1, n));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: integer to find sqrt of
 * Return: natural square root or -1
 */

int _sqrt_recursion(int n)
{
	if (n == 0)
		return (0);
	return (check(1, n));
}
