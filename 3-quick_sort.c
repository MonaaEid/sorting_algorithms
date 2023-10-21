#include <stdio.h>
#include "sort.h"
/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * Quick sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}

/**
 * quick_sort_helper - Sorts a partition of an array of integers in ascending
 * order using the Quick sort algorithm.
 * @array: The array to be sorted.
 * @lo: The index of the first element in the partition to be sorted.
 * @hi: The index of the last element in the partition to be sorted.
 * @size: The size of the original array.
 */
void quick_sort_helper(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		quick_sort_helper(array, lo, p - 1, size);
		quick_sort_helper(array, p + 1, hi, size);
	}
}

/**
 * partitionn - Partitions a subarray of an array of integers using the Lomuto
 * partition scheme.
 * @array: The array to be partitioned.
 * @lo: The index of the first element in the subarray to be partitioned.
 * @hi: The index of the last element in the subarray to be partitioned.
 * @size: The size of the original array.
 *
 * Return: The final partition index.
 */
int partitionn(int *array, int lo, int hi, size_t size)
{
	int pivot = array[hi];
	int i = lo - 1;
	int j;

	for (j = lo; j <= hi - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[hi]);
	print_array(array, size);
	return (i + 1);
}
/**
 * partition - Partitions a subarray of an array of integers using the Lomuto
 * partition scheme.
 * @array: The array to be partitioned.
 * @left: The index of the first element in the subarray to be partitioned.
 * @right: The index of the last element in the subarray to be partitioned.
 * @size: The size of the original array.
 *
 * Return: The final partition index.
 */
int partition(int *array, int left, int right, size_t size)
{
	int tmp, i;
	int j;

	i = left - 1;

	for (j = left; j < right; j++)
	{
		if (array[j] < array[right])
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (array[right] < array[i + 1])
	{
		tmp = array[i + 1];
		array[i + 1] = array[right];
		array[right] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}
/**
 * swap - Swaps two integers in an array.
 * @a: The first integer to be swapped.
 * @b: The second integer to be swapped.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

