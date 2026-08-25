#include <stdio.h>
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
 * bitonic_merge - Merges a bitonic sequence in ascending or descending order
 * @array: An array of integers
 * @size: The full size of the original array
 * @start: The starting index of the sequence to merge
 * @seq: The size of the sequence to merge
 * @dir: The direction to sort (1 for UP, 0 for DOWN)
 */
void bitonic_merge(int *array, size_t size, size_t start, size_t seq, char dir)
{
	size_t i, step = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + step; i++)
		{
			if ((dir == 1 && array[i] > array[i + step]) ||
			    (dir == 0 && array[i] < array[i + step]))
				swap_ints(&array[i], &array[i + step]);
		}
		bitonic_merge(array, size, start, step, dir);
		bitonic_merge(array, size, start + step, step, dir);
	}
}

/**
 * bitonic_seq - Builds a bitonic sequence recursively
 * @array: An array of integers
 * @size: The full size of the original array
 * @start: The starting index of the building sequence
 * @seq: The size of the building sequence
 * @dir: The direction to sort (1 for UP, 0 for DOWN)
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t seq, char dir)
{
	size_t cut = seq / 2;
	char *str = (dir == 1) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_seq(array, size, start, cut, 1);
		bitonic_seq(array, size, start + cut, cut, 0);
		bitonic_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 *                using the Bitonic sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_seq(array, size, 0, size, 1);
}
