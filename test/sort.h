#ifndef SORT_H
#define SORT_H
/* Library import */
#include <stddef.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node.
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* print array prototype */
void print_array(const int *array, size_t size);
/* print list prototype */
void print_list(const listint_t *list);
/* Bubble Sort prototype */
void bubble_sort(int *array, size_t size);
/* Insertion sort prototype */
void insertion_sort_list(listint_t **list);
/* Selection sort prototype */
void selection_sort(int *array, size_t size);
/* Quick sort prototype */
void quick_sort(int *array, size_t size);

#endif
