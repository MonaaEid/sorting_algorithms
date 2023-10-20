#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * counting_sort - Sorts an array of integers in ascending order using the
 * Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int i, max = 0;
	int *count = NULL, *output = NULL;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	count = calloc(max + 1, sizeof(int));
	output = malloc(size * sizeof(int));
	if (count == NULL || output == NULL)
		return;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	printf("Counting array: ");
	for (i = 0; i <= max; i++)
		printf("%d%s", count[i], i == max ? "\n" : ", ");

	free(count);
	free(output);
}
