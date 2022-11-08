#include "sort.h"

/**
 * selection_sort - sorting using selection sort algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min;
	int tmp;

	i = 0;
	min = 0;
	tmp = 0;
	j = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j <= size - 1)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
			j++;
		}
		if (i != min)
		{
			tmp = array[i];
			array[i] = array[min];
			array[min] = tmp;
			print_array(array, size);
		}
		i++;
	}
}
