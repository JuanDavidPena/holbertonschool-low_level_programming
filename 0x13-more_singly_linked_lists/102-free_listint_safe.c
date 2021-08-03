#include "lists.h"
#include <stdio.h>

size_t looped_list_unique(const listint_t *head);
size_t free_listint_safe(listint_t **h);

/**
 * looped_list_unique - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the start of the listint_t.
 * Return: If the list is not looped - 0.
 *         Or the number of unique nodes in the list.
 */
size_t looped_list_unique(const listint_t *head)
{
	const listint_t *a, *b;
	size_t nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	a = head->next;
	b = (head->next)->next;

	while (b)
	{
		if (a == b)
		{
			a = head;
			while (a != b)
			{
				nodes++;
				a = a->next;
				b = b->next;
			}

			a = a->next;
			while (a != b)
			{
				nodes++;
				a = a->next;
			}

			return (nodes);
		}

		a = a->next;
		b = (b->next)->next;
	}

	return (0);
}

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
