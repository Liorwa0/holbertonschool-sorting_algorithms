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
 * lomuto_partition - Partition a subset of an array of integers
 *                    according to lumoto scheme (last element as pivot)
 * @array: The array of integers
 * @size: The size of the array
 * @low: The starting index of the subset to partition
 * @high: The ending index of the subset to partition
 *
 * Return: The final partition index
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot, above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap_ints(array + above, array + below);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomuto_sort - Implement the quicksort algorithm through recursion
 * @array: An array of integers to sort
 * @size: The size of the array
 * @low: The starting index of the array partition to order
 * @high: The ending index of the array partition to order
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, pivot - 1);
		lomuto_sort(array, size, pivot + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending
 *              order using the Quick sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
