#include "sort.h"

/**
 * swap_me - swaps two ints
 * @x: first integer to be swapped
 * @y: Second integer to be swapped
 */

void swap_me(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * shell_sort - Sorts elements in an array using Knuth sequence
 * @array: Array of integers
 * @size: Size of array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;

	if (array == NULL || size < 2)
		return;

	while (gap < (size / 3))
		gap = gap * 3 + 1;


	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_me(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
		gap /= 3;
	}
}
