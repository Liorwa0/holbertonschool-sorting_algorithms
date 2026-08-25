#include "sort.h"

/**
 * swap_ints - Swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partitions an array using the Hoare scheme
 * @array: The array of integers to sort
 * @size: The total size of the array
 * @left: The starting index of the partition
 * @right: The ending index of the partition (contains pivot)
 *
 * Return: The final partition index
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot = array[right];
	int i = left - 1;
	int j = right + 1;

	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);

		do {
			j--;
		} while (array[j] > pivot);

		if (i >= j)
			return (i);

		swap_ints(&array[i], &array[j]);
		print_array(array, size);
	}
}

/**
 * hoare_sort - Implements the Quick sort algorithm recursively
 * @array: An array of integers to sort
 * @size: The total size of the array
 * @left: The starting index of the subarray to sort
 * @right: The ending index of the subarray to sort
 */
void hoare_sort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = hoare_partition(array, size, left, right);
		hoare_sort(array, size, left, p - 1);
		hoare_sort(array, size, p, right);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm (Hoare partition)
 * @array: An array of integers
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	hoare_sort(array, size, 0, size - 1);
}
