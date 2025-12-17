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
listint_t *B;
if (list == NULL)
	return;
current = (*list)->next;
if (current->next == NULL && current->prev == NULL)
	return;
while (current != NULL)
{
	if (current->n < current->prev->n)
	{
		A = current->prev;
		B = current->next;
		current->prev->next = current->next;
		if (current->next != NULL)
		current->next->prev = current->prev;
		current->next = A;
		current->prev = A->prev;
		A->prev = current;
		if (current->prev != NULL)
			current->prev->next = current;
		else
			*list = current;
		print_list(*list);
	}
	else
	current = current->next;
}
}
