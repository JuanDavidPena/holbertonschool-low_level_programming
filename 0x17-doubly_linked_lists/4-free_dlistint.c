#include "lists.h"

/**
 * free_dlistint - free a list
 * @head:list
 * Return:void
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *start, *tmp;

	start = head;
	while (start != NULL)
	{
		tmp = start->next;
		free(start);
		start = tmp;
	}
}
