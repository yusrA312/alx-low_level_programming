#include "lists.h"
#include <stdio.h>
/**
 * print_dlistint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_dlistint(const dlistint_t *h)

{int i = 0;
	for (; h != NULL  ; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}

	return (i);
}
