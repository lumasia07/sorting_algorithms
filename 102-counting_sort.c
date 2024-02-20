#include "sort.h"

/**
 * get_max_val - Gets maximum value
 * @array: Array of integers
 * @size: Size of array
 * Return: Max Value
 */
int get_max_val(int *array, int size)
{
	int max_val, i;

	for (max_val = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max_val)
			max_val = array[i];
	}

	return (max_val);
}



/**
 * counting_sort - Sorts using counting sort algo
 * @array: Array to br sorted
 * @size: The size of the array
 */
void counting_sort(int *array, size_t size)
{
	int max_val, *count_arr, j, *output_arr;
	size_t i;

	if (array == NULL || size < 2)
		return;
	max_val = get_max_val(array, size);
	count_arr = malloc((max_val + 1) * sizeof(int));

	if (count_arr == NULL)
		return;

	for (j = 0; j <= max_val; j++)
		count_arr[j] = 0;

	for (i = 0; i < size; i++)
		count_arr[array[i]]++;

	for (j = 1; j <= max_val; j++)
		count_arr[j] += count_arr[j - 1];
	print_array(count_arr, max_val + 1);
	output_arr = malloc(size * sizeof(int));

	if (output_arr == NULL)
	{
		free(count_arr);
		return;
	}

	for (j = size - 1; j >= 0; j--)
	{
		output_arr[count_arr[array[j]] - 1] = array[j];
		count_arr[array[j]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output_arr[i];

	free(output_arr);
	free(count_arr);

}

