#include "function_pointers.h"

/**
 * print_name - print name
 * @name : string
 * @f: function
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
	{
		return;
	}
	f(name);
}
