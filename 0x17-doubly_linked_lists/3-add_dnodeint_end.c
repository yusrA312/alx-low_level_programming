nclude "lists.h"

/**
 * add_nodeint_end - adds a node at the end of a linked list
 * @head: pointer to the first element in the list
 * @n: data to insert in the new element
 *
 * Return: pointer to the new node, or NULL if it fails
 */
dlistint_t *add_nodeint_end(dlistint_t **head, const int n)
{
	listint_t *ptr;
	listint_t *tem = *head;

	ptr = malloc(sizeof(listint_t));
	if (!ptr)
		return (NULL);

	ptr->n = n;
	ptr->prev = NULL;
	ptr->next = NULL;

	if (*head == NULL)
	{
		*head = ptr;
		return (ptr);
	}

	for  (; tem->next ;)
		tem = tem->next;

	ptr->prev = tem;
	tem->next = ptr;


	return (ptr);

