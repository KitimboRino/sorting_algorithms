#include "sort.h"

/**
 * shell_sort - A function that sorts an array using the Shell sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */
void shell_sort(int *array, size_t size)
{
unsigned int i = 0, j = 0, gap = 0;
int aux = 0;

/* Check if the array is NULL or has less than two elements */
if (array == NULL || size < 2)
return;

/* Calculate the initial gap value for the Shell sort */
while (gap < size / 3)
gap = gap * 3 + 1;

/* Iterate through the gaps in the sequence */
for (; gap > 0; gap = (gap - 1) / 3)
{
/* Iterate through the elements in the array */
for (i = gap; i < size; i++)
{
aux = array[i];

/* Compare and swap elements with a gap */
for (j = i; j >= gap && array[j - gap] > aux; j -= gap)
{
/* Move elements within the gap */
if (array[j] != array[j - gap])
array[j] = array[j - gap];
}

/* Place the current element in its correct position */
if (array[j] != aux)
array[j] = aux;
}

/* Print the array after each gap iteration */
print_array(array, size);
}
}
