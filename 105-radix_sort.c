#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
 * radix_sort - sorts an array of integers in ascending order using the
 * Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;
	size_t i, lsd;
	int count_arr[10] = {0}, *out_arr, l, m;
	size_t k, n;

	if (!array || size < 2)
		return;

	max = 0;
	for (i = 0; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (lsd = 1; max / lsd > 0; lsd *= 10)
	{
		out_arr = malloc(sizeof(int) * size);

		for (k = 0; k < size; k++)
			count_arr[(array[k] / lsd) % 10]++;
		for (l = 1; l < 10; l++)
			count_arr[l] += count_arr[l - 1];

		for (m = size - 1; m >= 0; m--)
		{
			out_arr[count_arr[(array[m] / lsd) % 10] - 1] = array[m];
			count_arr[(array[m] / lsd) % 10]--;
		}

		for (n = 0; n < size; n++)
			array[n] = out_arr[n];

		free(out_arr);
		print_array(array, size);
	}
}
