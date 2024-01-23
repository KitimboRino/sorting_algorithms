#include "sort.h"

/**
 * bubble_sort - A function for bubble sorting.
 * @array: The array to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */
void bubble_sort(int *array, size_t size)
{
size_t i = 0, j = 0;
int aux = 0;

/* Check if the array is NULL or empty */
if (array == NULL || size == 0)
return;

/* Iterate through the array using two nested loops */
for (; i < size - 1; i++)
{
for (j = 0; j < size - i - 1; j++)
{
/* Compare adjacent elements and swap if they are in the wrong order */
if (array[j] > array[j + 1])
{
/* Perform the swap */
aux = array[j + 1];
array[j + 1] = array[j];
array[j] = aux;

/* Print the array after each swap */
print_array(array, size);
}
}
}
}
