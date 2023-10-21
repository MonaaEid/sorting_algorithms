#include <stdio.h>
#include "sort.h"
/**
 * heap_sort - Sorts an array of integers in ascending order using the
 * Heap sort algorithm with the sift-down approach.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;
	if (array == NULL || size < 2)
		return;

	for (i = (int)size / 2 - 1; i >= 0; i--)
		sift_down(array, (int)size, i);

	for (i = (int)size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, i, 0);
	}
}

/**
 * sift_down - Sifts down a node in a binary tree to
 * maintain the heap property.
 * @array: The array containing the binary tree.
 * @size: The size of the binary tree.
 * @i: The index of the node to be sifted down.
 */
void sift_down(int *array, int size, int i)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if (left < size && array[left] > array[max])
		max = left;
	if (right < size && array[right] > array[max])
		max = right;
	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, size);
		sift_down(array, size, max);
	}
}
