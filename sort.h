#ifndef SORT_H_
#define SORT_H_
#include <stddef.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void selection_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);

void quick_sort(int *array, size_t size);
void quick_sort_helper(int *array, int lo, int hi, size_t size);
int partitionn(int *array, int lo, int hi, size_t size);
int partition(int *array, int left, int right, size_t size);
void swap(int *a, int *b);
void shell_sort(int *array, size_t size);
void swap_nodes(listint_t *node1, listint_t *node2, listint_t **list);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_sort_helper(int *array, int lo, int hi, int *temp);
void merge(int *array, int lo, int mid, int hi, int *temp);
void heap_sort(int *array, size_t size);
void sift_down(int *array, int size, int i);
void radix_sort(int *array, size_t size);
#endif
