#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked lists
 * @h: linked list of type listint_t to traverse
 *
 * Return: number of nodes
 */
size_t listint_len(const listint_t *h)

{
	int i = 0;

	if (h == NULL)
		printf("The list is empty");
	else
		while(h)
		{
			i++;
			h = h->next;
		}

	return (i);
}
