#include "sort.h"
#include <stddef.h>
/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                        order using the Insertion sort algorithm.
 * @list: A pointer to the head of the doubly linked list to be sorted.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		temp = current->prev;
		while (temp != NULL && temp->n > current->n)
		{
			temp->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp;
			current->next = temp;
			current->prev = temp->prev;
			temp->prev = current;
			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
			temp = current->prev;
		}
		current = current->next;
	}
}
