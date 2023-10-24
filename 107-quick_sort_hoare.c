#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * quick_sort_hoare - sorts an array of integers in ascending order using the
 * Quick sort algorithm with Hoare partition scheme
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	q_sort_hoare(array, 0, size - 1, size);
}

/**
 * q_sort_hoare - recursive function that sorts an array of integers in asc
 * order using the Quick sort algorithm with Hoare partition scheme
 * @array: array to be sorted
 * @lo: lower index of the partition to be sorted
 * @hi: higher index of the partition to be sorted
 * @size: size of the array
 */
void q_sort_hoare(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = hoare_partition(array, lo, hi, size);
		q_sort_hoare(array, lo, p, size);
		q_sort_hoare(array, p + 1, hi, size);
	}
}

/**
 * hoare_partition - partitions an array of integers using the Hoare scheme
 * and returns the index of the pivot element
 * @array: array to be partitioned
 * @lo: lower index of the partition to be sorted
 * @hi: higher index of the partition to be sorted
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int hoare_partition(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j = hi + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (j);
		_swap(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * _swap - Swaps two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void _swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

