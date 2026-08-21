#include "sort.h"

/**
 * get_max - Gets maximum value from array
 * @array: The array
 * @size: Size of the array
 * Return: Maximum value
 */
int get_max(int *array, int size)
{
	int max = array[0], i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * radix_counting_sort - Counting sort for radix sort based on sig digit
 * @array: The array to sort
 * @size: Size of the array
 * @sig: Significant digit to sort by
 * @buff: Buffer to use for sorting
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0}, i;

	for (i = 0; i < (int)size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array using Radix sort algorithm
 * @array: The array to sort
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
/* Radix sort check */
