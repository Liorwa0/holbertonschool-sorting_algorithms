#include <stdlib.h>
#include "sort.h"

/**
 * get_max_val - Gets the maximum value in an array of integers
 * @array: An array of integers
 * @size: The size of the array
 *
 * Return: The maximum integer in the array
 */
int get_max_val(int *array, size_t size)
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
 * radix_counting_sort - Sorts the significant digits of an array in ascending
 *                       order using the counting sort algorithm
 * @array: An array of integers
 * @size: The size of the array
 * @sig: The significant digit to sort on
 * @buff: A buffer to store the sorted array
 */
void radix_counting_sort(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *              using the Radix sort algorithm (LSD)
 * @array: An array of integers
 * @size: The size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (!array || size < 2)
		return;

	max = get_max_val(array, size);
	buff = malloc(sizeof(int) * size);
	if (!buff)
		return;

	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_counting_sort(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
