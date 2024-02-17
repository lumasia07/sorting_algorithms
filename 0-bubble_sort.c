#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order using bubble sort
 * @array: Ponter to array of integers
 * @size: size of array
 * Return: Pointer to sorted array
 */
void bubble_sort(int *array, size_t size)
{
	int i, j;
	size_t n, m;

	if (size < 2)
		return;

	for (n = 0; n < size - 1; n++)
	{
		j = 0;

		for (m = 0; m < size - n - 1; m++)
		{
			if (array[m] > array[m + 1])
			{
				i = array[m];
				array[m] = array[m + 1];
				array[m + 1] = i;
				j = 1;
				print_array(array, size);
			}
		}
		if (j == 0)
			break;
	}
}
