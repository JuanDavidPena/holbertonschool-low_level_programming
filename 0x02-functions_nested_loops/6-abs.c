#include "holberton.h"

/**
 * _abs - returns abs of int .
 * @x: integer.
 * return: abs value
 */

int _abs(int x)
{
	if (x > 0)
	{
		return (x);
	}
	else if (x < 0)
	{
		return (x = x * -1);
	}
	else
		return (0);
}
