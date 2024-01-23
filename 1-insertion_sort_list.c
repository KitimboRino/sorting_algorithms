#include "sort.h"

/**
 * insertion_sort_list - function that sorts a doubly linked list
 *   of integers in ascending order using the Insertion
 *   sort algorithm
 * @list: doubly linked list
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
listint_t *node = NULL, *tmp = NULL;
/* Check if the list is NULL or has only one or zero elements */
if (list == NULL || *list == NULL || (*list)->next == NULL)
return;
/* Initialize the node pointer to the second element in the list */
node = *list;
node = node->next;
/* Iterate through the list */
while (node)
{
/* Compare and swap elements until the correct position is found */
while (node->prev && node->n < (node->prev)->n)
{
tmp = node;
/* Update the pointers to perform the swap */
if (node->next)
(node->next)->prev = tmp->prev;
(node->prev)->next = tmp->next;
node = node->prev;
tmp->prev = node->prev;
tmp->next = node;
/* Update the pointers after the swap */
if (node->prev)
(node->prev)->next = tmp;
node->prev = tmp;
/* Update the list pointer if needed */
if (tmp->prev == NULL)
*list = tmp;
/* Print the list after each swap */
print_list(*list);
node = node->prev;
}
node = node->next;
}
}
