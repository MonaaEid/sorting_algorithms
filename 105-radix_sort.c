#include <stdlib.h>
#include <stdio.h>
#include "sort.h"
/**
 * radix_sort - sorts an array of integers in ascending order using the
 *              Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
    int i, j, k;
    int max = 0;
    int exp = 1;
    int *bucket = NULL;

    if (!array || size < 2)
        return;

    bucket = malloc(sizeof(int) * 10);
    if (!bucket)
        return;

    for (i = 0; i < (int)size; i++)
        max = array[i] > max ? array[i] : max;

    while (max / exp > 0)
    {
        for (i = 0; i < 10; i++)
            bucket[i] = 0;

        for (i = 0; i < (int)size; i++)
            bucket[(array[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            bucket[i] += bucket[i - 1];

        for (i = size - 1; i >= 0; i--)
        {
            j = (array[i] / exp) % 10;
            k = --bucket[j];
            if (k != i)
            {
                array[k] ^= array[i];
                array[i] ^= array[k];
                array[k] ^= array[i];
                printf("%d", array[0]);
                for (j = 1; j < (int)size; j++)
                    printf(", %d", array[j]);
                printf("\n");
            }
        }
        exp *= 10;
    }
    free(bucket);
}
