#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order using
 * the Bubble sort
 *
 * @array: array to be sorted
 * @size: size of array
 *
 * Return: returns void
 */
void bubble_sort(int *array, size_t size)
{
	int sorted;
	size_t i;
	int j;

	sorted = 0;
	i = 0;
	j = 0;

	while (sorted == 0)
	{
		sorted = 1;
		for (i = 0; i <= size - 1; i++)
		{
			if (array[i] > array[i + 1] && (i + 1 < size))
			{
				j = array[i];
				array[i] = array[i + 1];
				array[i + 1] = j;
				sorted = 0;
				print_array(array, size);
			}
		}
	}
}
