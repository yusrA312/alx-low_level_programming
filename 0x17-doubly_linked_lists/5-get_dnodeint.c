#include "lists.h"

/**
 * get_dnodeint_at_index - Nth node
 *
 * @head: pointer to head node
 *
 * @index: int
 *
 * Return: dlistint_t
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;
	dlistint_t *ptr;

	ptr = head;

	if (!ptr)
		return (NULL);

	for (i = 0; ptr && i < index ; i++)
		ptr = ptr->next;
	if (!ptr)
		return (NULL);
	return (ptr);
}
