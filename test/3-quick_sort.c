#include "sort.h"
/* method prototypes */
size_t lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/**
 * lomuto_patition - Partitions the array using lomuto partition scheme.
 * @array: The array to the partitioned.
 * @low: The lower index of the partition to be sorted.
 * @high: The higher index of the partition to be sorted.
 * @size: Number of elements in @array.
 *
 * Description: Prints the array after each swap.
 *
 * Return: The new partition index.
 */
size_t lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, temp;
	int x, y;

	pivot = array[high];
	x = low - 1;

	for (y = low; y <= high - 1; y++)
	{
		if (array[y] < pivot)
		{
			x++;
			temp = array[x];
			array[x] = array[y];
			array[y] = temp;
			/* print the array after each swap when x != y */
			if (x != y)
				print_array(array, size);
		}
	}
	temp = array[x + 1];
	array[x + 1] = array[high];
	array[high] = temp;
	/* prnts the array after each swap when x+1 != high */
	if (x + 1 != high)
		print_array(array, size);
	return (x + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quick sort.
 * @array: The array to be sorted.
 * @low: Lower index of the partition to be sorted.
 * @high: Higher index of the partition to be sorted.
 * @size: Number of elements in @array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	size_t pindex;

	if (low < high)
	{
		pindex = lomuto_partition(array, low, high, size);
		/* Recursively sort the elements before and after the partition */
		if (pindex != 0 && pindex > (size_t)low)
			quick_sort_recursive(array, low, pindex - 1, size);
		quick_sort_recursive(array, pindex + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an integers array in ascending order.
 * @array: Array to be sorted.
 * @size: Number of elements in @array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_recursive(array, 0, (int)size - 1, size);
}
