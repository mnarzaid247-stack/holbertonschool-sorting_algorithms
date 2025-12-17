#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending
 *
 * @list: double pointer list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current;
listint_t *A;
if (list == NULL || *list == NULL || (*list)->next == NULL)
	return;
current = (*list)->next;
while (current != NULL)
{
	if (current->prev != NULL && current->n < current->prev->n)
	{
		A = current->prev;
		A->next = current->next;
		if (current->next != NULL)
		current->next->prev = A;
		current->next = A;
		current->prev = A->prev;
		A->prev = current;
		if (current->prev != NULL)
			current->prev->next = current;
		else
			*list = current;
		print_list(*list);
		current = current->prev;
	}
	else
	current = current->next;
}
}
