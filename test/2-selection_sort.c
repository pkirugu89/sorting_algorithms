#include "sort.h"

/**
 * selection_sort - Sorts integer arrays in ascending order
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 *
 * Return: Always 0
 */
void selection_sort(int *array, size_t size)
{
	size_t x, y, min_index;
	int temp;

	for (x = 0; x < size - 1; x++)
	{
		min_index = x;
		for (y = x + 1; y < size; y++)
		{
			if (array[y] < array[min_index])
				min_index = y;
		}
		if (min_index != x)
		{
			/* swap the elements */
			temp = array[x];
			array[x] = array[min_index];
			array[min_index] = temp;

			/* prints the array after swap */
			print_array(array, size);
		}
	}
}
