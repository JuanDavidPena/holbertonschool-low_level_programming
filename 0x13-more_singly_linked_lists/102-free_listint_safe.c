#include "lists.h"
#include <stdio.h>

size_t looped_list_unique(const listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * free_listint_safe - Frees a listint_t list that could have loops.
 * @h: A pointer to the address of
 *     the head of the listint_t list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tmp;
	size_t uniques, index;

	uniques = looped_list_unique(*h);

	if (uniques == 0)
	{
		for (; h != NULL && *h != NULL; uniques++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}
	}

	else
	{
		for (index = 0; index < uniques; index++)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
		}

		*h = NULL;
	}

	h = NULL;

	return (uniques);
}
