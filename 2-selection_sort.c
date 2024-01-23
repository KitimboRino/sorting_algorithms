#include "sort.h"

/**
 * selection_sort - A function that uses the selection sort algorithm.
 * @array: An array to sort.
 * @size: The size of the array.
 * Return: Nothing.
 */
void selection_sort(int *array, size_t size)
{
int aux = 0;
size_t i = 0, j = 0, pos = 0;

/* Check if the array is NULL or empty */
if (array == NULL || size == 0)
return;

/* Iterate through the array */
for (; i < size - 1; i++)
{
pos = i;

/* Find the index of the minimum element in the unsorted part of the array */
for (j = i + 1; j < size; j++)
{
if (array[j] < array[pos])
pos = j;
}

/* Swap found minimum element with the first element of the unsorted part */
if (pos != i)
{
aux = array[i];
array[i] = array[pos];
array[pos] = aux;

/* Print the array after each swap */
print_array(array, size);
}
}
}
