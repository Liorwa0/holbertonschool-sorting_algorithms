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
 * bitonic_merge - Bitonic merge subroutine
 * @array: The array
 * @size: Total size of the array
 * @low: Starting index
 * @count: Number of elements to merge
 * @dir: Direction (1 for UP, 0 for DOWN)
 */
void bitonic_merge(int *array, size_t size, size_t low, size_t count, char dir)
{
	size_t i, k;

	if (count > 1)
	{
		k = count / 2;
		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
				swap_ints(&array[i], &array[i + k]);
		}
		bitonic_merge(array, size, low, k, dir);
		bitonic_merge(array, size, low + k, k, dir);
	}
}

/**
 * bitonic_seq - Bitonic sequence generator
 * @array: The array
 * @size: Total size of the array
 * @low: Starting index
 * @count: Number of elements
 * @dir: Direction (1 for UP, 0 for DOWN)
 */
void bitonic_seq(int *array, size_t size, size_t low, size_t count, char dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%lu/%lu] (%s):\n", count, size, dir == 1 ? "UP" : "DOWN");
		print_array(array + low, count);
		bitonic_seq(array, size, low, k, 1);
		bitonic_seq(array, size, low + k, k, 0);
		bitonic_merge(array, size, low, count, dir);
		printf("Result [%lu/%lu] (%s):\n", count, size, dir == 1 ? "UP" : "DOWN");
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 1);
}
/* Bitonic sort check */
