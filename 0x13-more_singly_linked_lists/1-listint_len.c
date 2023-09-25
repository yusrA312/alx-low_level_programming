#include "lists.h"
#include <stdio.h>
/**
 * print_listint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t print_listint(const listint_t *h)
{int i = 0;
	if (h == NULL)
		printf("The list is empty");
	else
		for (; h != NULL ;)
		{
			h = h->next;
			i++;
		}

	return (i);
}
