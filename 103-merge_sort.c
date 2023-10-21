#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * merge_sort - Sorts an array of integers in ascending order using the
 * Merge sort algorithm with the top-down approach.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *temp = NULL;

	if (array == NULL || size < 2)
		return;
	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;
	merge_sort_helper(array, 0, size - 1, temp);
	free(temp);
}

/**
 * merge_sort_helper - Sorts a subarray of an array of integers in ascending
 * order using the Merge sort algorithm with the top-down
 * approach.
 * @array: The array to be sorted.
 * @lo: The index of the first element in the subarray to be sorted.
 * @hi: The index of the last element in the subarray to be sorted.
 * @temp: A temporary array to store intermediate results.
 */
void merge_sort_helper(int *array, int lo, int hi, int *temp)
{
	int mid;

	if (lo >= hi)
		return;
	mid = lo + (hi - lo) / 2;
	merge_sort_helper(array, lo, mid, temp);
	merge_sort_helper(array, mid + 1, hi, temp);
	merge(array, lo, mid, hi, temp);
}

/**
 * merge - Merges two sorted subarrays into a single sorted subarray.
 * @array: The array containing the two subarrays to be merged.
 * @lo: The index of the first element in the first subarray.
 * @mid: The index of the last element in the first subarray.
 * @hi: The index of the last element in the second subarray.
 * @temp: A temporary array to store intermediate results.
 */
void merge(int *array, int lo, int mid, int hi, int *temp)
{
	int i = lo;
	int j = mid + 1;
	int k = lo;

	while (i <= mid && j <= hi)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}
	while (i <= mid)
		temp[k++] = array[i++];	
	while (j <= hi)
		temp[k++] = array[j++];	
	for (k = lo; k <= hi; k++)
		array[k] = temp[k];
}
