#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * bitonic_sort - sorts an array of integers in ascending order using the
 *                Bitonic sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bitonic_sort(int *array, size_t size)
{
    if (!array || size < 2)
        return;

    bitonic_sort_recursive(array, 0, size, 1);
}

/**
 * bitonic_sort_recursive - recursive function that sorts an array of integers
 * in ascending order using the Bitonic sort algorithm
 * @array: array to be sorted
 * @start: starting index of the sub-array to be sorted
 * @size: size of the sub-array to be sorted
 * @dir: direction of sorting (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
    if (size > 1)
    {
        size_t i;
        size_t k = size / 2;

        for (i = start; i < start + k; i++)
        {
            if ((array[i] > array[i + k]) == dir)
            {
                _swap(&array[i], &array[i + k]);
                print_array(array, start, size);
            }
        }

        bitonic_sort_recursive(array, start, k, dir);
        bitonic_sort_recursive(array, start + k, k, dir);
    }
}
