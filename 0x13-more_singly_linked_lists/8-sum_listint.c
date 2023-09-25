#include "lists.h"

/**
 * sum_listint - calculates the sum of all the data in a listint_t list
 * @head: first node in the linked list
 *
 * Return: resulting sum
 */
int sum_listint(listint_t *head)
{
	int i;
	int sum;
	listint_t *ptr = head;

	if (!ptr)
		return (0);
	for (i = 0 ; ptr ; i++)
	{sum += ptr->n;
	ptr = ptr->next;
	}

	return (sum);
}

