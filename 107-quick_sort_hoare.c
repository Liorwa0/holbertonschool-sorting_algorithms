#include "sort.h"

/**
 * swap_ints - Swap two integers in an array
 * @a: First integer to swap
 * @b: Second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partition a subset of an array of integers
 *                   according to the Hoare partition scheme
 * @array: The array of integers
 * @size: The size of the array
 * @left: The starting index of the subset
 * @right: The ending index of the subset
 *
 * Return: The final partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap_ints(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}

/**
 * hoare_sort - Implement the quicksort algorithm through recursion
 * @array: An array of integers to sort
 * @size: The size of the array
 * @left: The starting index of the array partition
 * @right: The ending index of the array partition
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int pivot;

	if (right - left > 0)
	{
		pivot = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, pivot - 1);
		hoare_sort(array, size, pivot, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending
 *                    order using the Quick sort algorithm (Hoare scheme)
 * @array: An array of integers
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
/* Hoare sort check */
