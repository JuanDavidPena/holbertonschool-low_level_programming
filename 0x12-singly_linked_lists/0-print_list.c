#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: pointer to the list.
 * Return: number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	size_t len = 0;
	int i;

	for (i = 0; h; i++)
	{
		if (h->str == NULL)
			printf("[0] (nil)\n");
		else
			printf("[%d] %s\n", h->len, h->str);
	h = h->next;
	len++;
	}
	return (len);
}
