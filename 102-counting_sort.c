#include "sort.h"

/**
 * counting_sort - sort an array of integers using counting sor algorithm
 *
 * @array: array to be sorted
 * @size: size of the array
 *
 * Return: returns void
 */
void counting_sort(int *array, size_t size)
{
	int k, key;
	size_t i;
	int *output, *count;

	k = 0;
	key = 0;
	for (i = 0; i < size; i++)
		if (array[i] > k)
			k = array[i];
	count = malloc(sizeof(int) * (k + 1));
	if (count == NULL)
		return;
	for (i = 0; (int)i <= k; i++)
		count[i] = 0;

	for (i = 0; i < size; i++)
	{
		key = array[i];
		count[key] = count[key] + 1;
	}

	for (i = 1; (int)i <= k; i++)
	{
		count[i] = count[i] + count[i - 1];
	}
	print_array(count, k + 1);
	output = malloc(sizeof(int) * (size + 1));
	if (output == NULL)
	{
		free(count);
		return;
	}
	for (i = 0; i < size; i++)
	{
		key = array[i];
		count[key] = count[key] - 1;
		output[count[key]] = array[i];
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];
}
