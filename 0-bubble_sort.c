#include "sort.h"

/**
 * bubble_sort - Sort an array of integers in ascending order.
 * @array: An array of integers to sort.
 * @size: The array size.
 *
 * Description: Prints the array after each swap
 */
void bubble_sort(int *array, size_t size)
{
	int swap, temp;
	size_t i, j;

	/* Print the initial array
	print_array(array, size); */

	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				/* swap the elements */
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swap = 1;
				/* print the array after swap */
				print_array(array, size);
			}
		}
		/**
		 * if no swaps were made in a pass,
		 * the array is already sorted.
		 */
		if (!swap)
		{
			break;
		}
	}
}
