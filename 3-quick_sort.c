#include "sort.h"

/**
 * swap - swaps two elements
 * @a: first element
 * @b: second element
 */

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - partitions an array
 * @array: array to be partitioned
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: index of the pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low, j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
			i++;
		}
	}
	if (i != high)
	{
		swap(&array[i], &array[high]);
		print_array(array, size);
	}
	return (i);
}

/**
 * quick_sort_rec - sorts an array
 * @array: array to be sorted
 * @low: low index
 * @high: high index
 * @size: size of the array
 * Return: Nothing
 */

void quick_sort_rec(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_rec(array, low, pivot - 1, size);
		quick_sort_rec(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array
 * @array: array to be sorted
 * @size: size of the array
 * Retrun: Nothing
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_rec(array, 0, size - 1, size);
}
