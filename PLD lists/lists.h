#ifndef _LIST_H_
#define _LIST_H_
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct listint_s - singly linked list
 * @n: int to be stored.
 * @next: pointer to next int.
 */
typedef struct listint_s
{
	int n;
	struct listint_s *next;
} listint_t;

#endif
