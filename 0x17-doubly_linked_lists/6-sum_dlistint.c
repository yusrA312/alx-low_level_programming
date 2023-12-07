#include "lists.h"

/**
 * sum_dlistint - Sum of all data (n)
 *
 * @head: Head of node
 *
 * Return: void
 */

int sum_dlistint(dlistint_t *head)
{
	int i;
	int sum =  0;
	dlistint_t *ptr = head;

	if (!ptr)
		return (0);
	for (i = 0 ; ptr ; i++)
	{sum += ptr->n;
		ptr = ptr->next;
	}

	return (sum);
}
