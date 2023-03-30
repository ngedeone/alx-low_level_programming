#include <stdlib.h>
#include "lists.h"
#include <stdarg.h>

/**
 * free_list - Frees a list_t list
 * @head: A pointer to the list_t list
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
