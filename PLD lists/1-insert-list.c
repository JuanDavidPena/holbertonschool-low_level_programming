#include "lists.h"

listint_t *insert_list(listint_t *insert, listint_t *insert_to, unsigned int index)
{
    listint_t *t, *tmp1, *tmp2, *red = insert_to, *green = insert;
    unsigned int i = 0, counter = 0;

    if (red == NULL)
    {
        red = insert;
        return (insert);
    }
    if (index == 0)
    {   
        printf("hola\n");
        t = green;
        while(green->next != NULL)
        {
            green = green->next;
        }
        green->next = red;
        red = insert;
        return (red);
    }

    t = insert;

    while (insert->next != NULL)
    {
        insert = insert->next;
    }
    while (red->next != NULL && counter < index - 1)
    {
        red = red->next;
        counter++;
    }
    printf("%d", counter);
    tmp1 = red;
    tmp2 = red->next;

    red->next = t;
    insert->next = tmp2;

    return(insert_to);
}
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



int main()
{
	listint_t *head, *red;

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
    printf("\n");

    red = NULL;
	add_nodeint(&red, 5);
	add_nodeint(&red, 5);
	add_nodeint(&red, 5);
	add_nodeint(&red, 5);
	add_nodeint(&red, 5);
	add_nodeint(&red, 5);
	add_nodeint(&red, 5);
	add_nodeint(&red, 5);
	print_listint_safe(red);
    printf("\n");


    insert_list(head, red, 2);
    print_listint_safe(red);

	return (0);
}

