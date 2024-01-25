#include "sort.h"

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
int max, i;

/* Initialize max with the first element in the array */
for (max = array[0], i = 1; i < size; i++)
{
/* Update max if a larger element is found */
if (array[i] > max)
max = array[i];
}

return (max);
}

/**
 * radix_counting_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @buff: A buffer to store the sorted array.
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
int count[10] = {0}; /* Count array for counting sort */
size_t i;

/* Count the occurrences of each digit at the current significant position */
for (i = 0; i < size; i++)
count[(array[i] / sig) % 10] += 1;

/* Update count array to store position of each digit in the sorted order */
for (i = 1; i < 10; i++)
count[i] += count[i - 1];

/* Build the sorted array using the count array */
for (i = size - 1; (int)i >= 0; i--)
{
buff[count[(array[i] / sig) % 10] - 1] = array[i];
count[(array[i] / sig) % 10] -= 1;
}

/* Copy the sorted array back to the original array */
for (i = 0; i < size; i++)
array[i] = buff[i];
}

/**
 * radix_sort - Sort an array of integers in ascending
 *              order using the radix sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Implements the LSD radix sort algorithm. Prints
 * the array after each significant digit increase.
 */
void radix_sort(int *array, size_t size)
{
int max, sig, *buff;

/* Check if the array is NULL or has less than two elements */
if (array == NULL || size < 2)
return;

/* Allocate memory for the buffer array */
buff = malloc(sizeof(int) * size);
if (buff == NULL)
return;

/* Find the maximum value in the array */
max = get_max(array, size);

/* Perform radix sort for each significant digit */
for (sig = 1; max / sig > 0; sig *= 10)
{
/* Use sort to sort array based on current significant digit */
radix_counting_sort(array, size, sig, buff);
/* Print the array after each significant digit increase */
print_array(array, size);
}

/* Free the allocated memory for the buffer array */
free(buff);
}
