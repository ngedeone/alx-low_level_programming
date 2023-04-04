#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list and sets the head to NULL.
 * @h: A pointer to the head of the list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t count = 0;
	listint_t *current, *temp;

	if (h == NULL || *h == NULL)
		return (0);

	current = *h;
	*h = NULL;

	while (current != NULL)
	{
		count++;
		temp = current;
		current = current->next;

		/* Check if we have reached a loop */
		if (temp < current)
		{
			free(temp);
			break;
		}

		free(temp);
	}

	return (count);
}
