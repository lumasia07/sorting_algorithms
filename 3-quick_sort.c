#include "sort.h"

/**
 * swap_me - swaps integers in the array
 * @x: integer to be swapped
 * @y: integer to be swapped
 */
void swap_me(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * lomuto_algo - partitions array of integers with last element as pivot
 * @array: array of integers
 * @size: size of array
 * @left: start index of subset to order
 * @right: end index of subset to order
 * Return: final partition of index
 */
int lomuto_algo(int *array, size_t size, int left, int right)
{
	int *piv, greater, lesser;

	piv = array + right;

	for (greater = lesser = left; lesser < right; lesser++)
	{
		if (array[lesser] < *piv)
		{
			if (greater < lesser)
			{
				swap_me(array + lesser, array + greater);
				print_array(array, size);
			}
			greater++;
		}
	}

	if (array[greater] > *piv)
	{
		swap_me(array + greater, piv);
		print_array(array, size);
	}
	return (greater);
}

/**
 * lomuto_recursive_sort - implement quick sort through recursion
 * @array: Array of integers to sort
 * @size: Size of array
 * @left: start index of array to partition to order
 * @right: end index of array to partition to order
 */
void lomuto_recursive_sort(int *array, size_t size, int left, int right)
{
	int partition;

	if (right - left > 0)
	{
		partition = lomuto_algo(array, size, left, right);
		lomuto_recursive_sort(array, size, left, partition - 1);
		lomuto_recursive_sort(array, size, partition + 1, right);
	}
}

/**
 * quick_sort - Sorts an array of integers using quick soet algo
 * @array: Array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_recursive_sort(array, size, 0, size - 1);
}
