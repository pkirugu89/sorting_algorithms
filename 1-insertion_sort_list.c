#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using insertion sort.
 * @list: A pointer to the head pointer of the list.
 *
 * Return: Always 0
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	/**
	 * check if the list is empty or has only one element.
	 * no need to sort.
	 */
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && prev->n > current->n)
		{
			/* swap the nodes */
			if (prev->prev != NULL)
				prev->prev->next = current;
			if (current->next != NULL)
				current->next->prev = prev;

			prev->next = current->next;
			current->prev = prev->prev;

			prev->prev = current;
			current->next = prev;
			/* Update the list head if needed */
			if (current->prev == NULL)
				*list = current;
			/* print the list after each swap */
			print_list(*list);

			prev = current->prev;
		}
		current = current->next;
	}
}
