#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t linked
 * @head: double pointer to the head of the list
 * @index: index of the node to delete (starting from 0)
 *
 * Return: 1 if succeeded, -1 if failed
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *prev;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
		return (1);
	}
	prev = *head;
	current = (*head)->next;
	for (i = 1; current != NULL && i <= index; i++)
	{
		if (i == index)
		{
			prev->next = current->next;
			free(current);
			return (1);
		}
		prev = current;
		current = current->next;
	}
	return (-1);
}
