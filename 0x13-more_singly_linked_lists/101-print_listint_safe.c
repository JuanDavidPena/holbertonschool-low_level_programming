#include "lists.h"
#include <stdio.h>

size_t looped_list_unique(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

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
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t unique, index = 0;

	unique = looped_list_unique(head);

	if (unique == 0)
	{
		for (; head != NULL; unique++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < unique; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (unique);
}
