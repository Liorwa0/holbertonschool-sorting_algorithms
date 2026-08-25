#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Returns the maximum integer in an array
 * @array: An array of integers
 * @size: The size of the array
 *
 * Return: The maximum integer in the array
 */
int get_max(int *array, size_t size)
{
	int max;
	size_t i;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output, max;
	size_t i;

	if (!array || size < 2)
		return;

	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (!count)
		return;

	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
		count[array[i]] += 1;

	for (i = 1; i <= (size_t)max; i++)
		count[i] += count[i - 1];

	print_array(count, max + 1);

	output = malloc(sizeof(int) * size);
	if (!output)
	{
		free(count);
		return;
	}

	for (i = 0; i < size; i++)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(count);
	free(output);
}
