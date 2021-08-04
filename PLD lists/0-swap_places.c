#include "lists.h"

/**
 * get_nodeint_at_index - return nth node index
 * @head:pointer to start of the list.
 * @index:given index int
 * Return:Null or index of node
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	size_t x;

	for (x = 0; x < index && head->next; x++)
	{
		head = head->next;
	}
	if (x < index)
		return (NULL);
	return (head);
}

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

/**
 * add_nodeint - add node list
 * @head:pointer to the first node of the list.
 * @n:int to add to the list
 * Return: new node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->next = *head;
	new->n = n;
	*head = new;
	return (new);
}

listint_t *swap_places(listint_t **head, unsigned int index1, unsigned int index2)
{
	listint_t *temporal1, *temporal2, *next2, *tmp1, *tmp2, *lista = *head;
	unsigned int counter = 0, count2 = 0, flag1 = 0, flag2 = 0;

	if (index1 == 0 || index2 == 0)
	{
		if (index1 == 0)
		{
			tmp1 = lista;
			flag1 = 1;
		}
		if (index2 == 0)
		{
			tmp2 = lista;
			flag2 = 1;
		}
	}
	while (lista)
	{	
		if (counter == index1 - 1)
		{
			flag1 = 1;
			tmp1 = lista;
			printf("%d", tmp1->n);
		}
		else if (counter == index2 - 1)
		{
			flag2 = 1;
			tmp2 = lista;
			printf("%d", tmp2->n);
		}
		counter++;
		lista = lista->next;
	}
	printf("%d", counter);
	lista = *head;

	if (flag1 == 1 && flag2 == 1)
	{
		temporal1 = tmp1->next;
		temporal2 = tmp2->next;
		tmp1->next = temporal2;
		next2 = temporal2->next;
		temporal2->next = temporal1->next;
		tmp2->next = temporal1;
		temporal1->next = next2;
	}
	printf("%d", count2);
}

int main()
{
	listint_t *head;

	head = NULL;
	add_nodeint(&head, 0);
	add_nodeint(&head, 1);
	add_nodeint(&head, 2);
	add_nodeint(&head, 3);
	add_nodeint(&head, 4);
	add_nodeint(&head, 98);
	add_nodeint(&head, 402);
	add_nodeint(&head, 1024);
	print_listint_safe(head);
	swap_places(&head, 0, 7);

	print_listint_safe(head);

	return (0);
}
