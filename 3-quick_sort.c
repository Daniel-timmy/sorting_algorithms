#include "sort.h"

/**
 * partition - partitions the array
 *
 * @array: array to be sorted
 * @lo: lowest index in array
 * @hi: highest index in the array
 * @size: size of array
 *
 * Return: returns void
 */

size_t partition(int *array, size_t lo, size_t hi, size_t size)
{
	int p, tmp;
	size_t i, j;

	i = lo;
	p = array[hi];

	for (j = lo; j < hi; j++)
	{
		if (array[j] < p)
		{
			if (i != 0)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
				i++;
			}
		}
	}

	tmp = array[i];
	array[i] = array[hi];
	array[hi] = tmp;
	print_array(array, size);
	return (i);
}
/**
 * q_sort - sort an array using the quick sort algorithm
 *
 * @array: array to be sorted
 * @lo: lowest index
 * @hi: highest index
 * @size: size of the array
 *
 * Return: void
 */
void q_sort(int *array, size_t lo, size_t hi, size_t size)
{
	int pivot;

	if (lo < hi)
	{
		pivot = partition(array, lo, hi, size);
		q_sort(array, lo, pivot - 1, size);
		q_sort(array, pivot + 1, hi, size);
	}
}

/**
 * quick_sort - driver functio
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: return void
 */
void quick_sort(int *array, size_t size)
{
	q_sort(array, 0, size - 1, size);
}
