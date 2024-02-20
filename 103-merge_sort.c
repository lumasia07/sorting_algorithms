#include "sort.h"

/**
 * merge_sort - merges using Merge sort algo
 * @array: An array of integers
 * @size: Size of array
 */
void merge_sort(int *array, size_t size)
{
	size_t split, size_left, size_right;
	int *right, *left;

	if (array == NULL || size < 2)
		return;

	split = size / 2;

	left = array;
	right = array + split;

	size_left = split;
	size_right = size - split;

	merge_sort(left, size_left);
	merge_sort(right, size_right);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, size_left);
	printf("[right]: ");
	print_array(right, size_right);

	merge_me(array, left, size_left, right, size_right);
	
	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_me - mergees the two sub-arrays
 * @array: Output array
 * @left: Left sub-array
 * @right: Right sub-array
 * @size_right: Size of right sub-array
 * @size_left: Size od lrft sub-array
 */
void merge_me(int *array, int *left, int size_left, int *right, int size_right)
{
	int cp, *merged, x = 0, y = 0, z = 0;

	merged = malloc((size_left + size_right) * sizeof(int));

	if (merged == NULL)
		return;

	while (x < size_left && y < size_right)
	{
		if (left[x] <= right[y])
			merged[z++] = left[x++];
		else
			merged[z++] = right[y++];
	}

	while (x < size_left)
		merged[z++] = left[x++];

	while (y < size_right)
		merged[z++] = right[y++];

	for (cp = 0; cp < size_left + size_right; cp++)
		array[cp] = merged[cp];

	free(merged);
}
