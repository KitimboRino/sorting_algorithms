#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/* Function prototype for merge_partition */
void merge_partition(size_t lo, size_t hi, int *array, int *base);

/**
 * merge_sort - A function that sorts an array using the merge algorithm.
 * @array: The array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void merge_sort(int *array, size_t size)
{
size_t i = 0;
int *base = NULL;

/* Check if the array is NULL or has less than 2 elements */
if (array == NULL || size < 2)
return;

/* Allocate memory for a temporary array to store copy of original array */
base = malloc(sizeof(int) * size);
if (base == NULL)
return;

/* Copy the elements of the original array to the temporary array */
for (; i < size; i++)
base[i] = array[i];

/* Call the recursive merge_sort function */
merge_partition(0, size, array, base);

/* Free the allocated memory for the temporary array */
free(base);
}

/**
 * merge - A function that sorts the subarrays.
 * @lo: Lower index.
 * @mi: Middle index.
 * @hi: Higher index.
 * @dest: Destination for data.
 * @src: Input data.
 * Return: Nothing.
 */
void merge(size_t lo, size_t mi, size_t hi, int *dest, int *src)
{
size_t i = 0, j = 0, k = 0;

/* Display the current merging step for visualization */
printf("Merging...\n");
printf("[left]: ");
print_array(src + lo, mi - lo);
printf("[right]: ");
print_array(src + mi, hi - mi);

i = lo;
j = mi;
k = lo;

/* Merge the subarrays back into the original array */
for (; k < hi; k++)
{
if (i < mi && (j >= hi || src[i] <= src[j]))
{
dest[k] = src[i];
i++;
}
else
{
dest[k] = src[j];
j++;
}
}

/* Display the merged array for visualization */
printf("[Done]: ");
print_array(dest + lo, hi - lo);
}

/**
 * merge_partition - A function that splits the array recursively.
 * @lo: Lower index.
 * @hi: Higher index.
 * @array: The array to sort.
 * @base: The copy of the array.
 * Return: Nothing.
 */
void merge_partition(size_t lo, size_t hi, int *array, int *base)
{
size_t mi = 0;

/* Base case: If the subarray has 1 or 0 elements, it is already sorted */
if (hi - lo < 2)
return;

/* Calculate the middle index of the subarray */
mi = (lo + hi) / 2;

/* Recursively sort the left and right subarrays */
merge_partition(lo, mi, array, base);
merge_partition(mi, hi, array, base);

/* Merge the sorted subarrays */
merge(lo, mi, hi, array, base);

/* Copy the merged elements back to the original array */
for (mi = lo; mi < hi; mi++)
base[mi] = array[mi];
}
