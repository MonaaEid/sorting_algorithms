#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm.
 * @list: A pointer to the head of the doubly linked list to be sorted.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start = NULL, *end = NULL, *current = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do {
		swapped = 0;
		for (current = start = *list; current->next != end; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(current, current->next, list);
				swapped = 1;
				print_list(*list);
			}
		}
		end = current;
		if (!swapped)
			break;
		swapped = 0;
		for (current = end; current != start; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(current->prev, current, list);
				swapped = 1;
				print_list(*list);
			}
		}
		start = current->next;
	} while (swapped);
}

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @node1: A pointer to the first node to be swapped.
 * @node2: A pointer to the second node to be swapped.
 * @list: A pointer to the head of the doubly linked list.
 */
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list)
{
	if (node1 == NULL || node2 == NULL || list == NULL || *list == NULL)
		return;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
}
