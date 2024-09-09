#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *temp;
	dlistint_t *to_delete;
	unsigned int i;

	if (*head == NULL)
	{
		return (-1);
	}
	temp = *head;
	for (i = 0; i < index; i++)
	{
		if (temp == NULL)
		{
			return (-1);
		}
		temp = temp->next;
	}
	if (temp == NULL)
	{
		return (-1);
	}
	to_delete = temp;
	if (to_delete->prev != NULL)
	{
		to_delete->prev->next = to_delete->next;
	}
	else
	{
		*head = to_delete->next;
	}
	if (to_delete->next != NULL)
	{
		to_delete->next->prev = to_delete->prev;
	}
	free(to_delete);
	return (1);
}
