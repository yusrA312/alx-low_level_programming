#include "lists.h"
#include <stdio.h>
/**
 * print_listint - prints all the elements of a linked list
 * @h: linked list of type listint_t to print
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)
{int i = 0;
	if (h == NULL)
		printf("The list is empty");
	else
		for (i=0; h != NULL ;)
		{
			h = h->next;
			i++;
		}

	return (i);
}
