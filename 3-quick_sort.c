#include "sort.h"
/**
* lomuto_partition - partitions the array using the Lomuto partition scheme
* @array: pointer to the array to be partitioned
* @size: size of the array
* @low: starting index of the sub-array
* @high: ending index of the sub-array
* Return: index of the pivot element after partitioning
*/
int lomuto_partition(int *array, size_t size, size_t low, size_t high)
{
	int pivot = array[high];

	size_t i = low - 1;
	int temp;

	size_t j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	if (i + 1 != high)
	{
		temp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}
/**
* quick_sort_recursive - recursive function to perform quick sort
* @array: pointer to the array to be sorted
* @size: size of the array
* @low: starting index of the sub-array
* @high: ending index of the sub-array
*/
void quick_sort_recursive(int *array, size_t size, size_t low, size_t high)
{
	size_t pivot_index;

	if (low < high)
	{
		pivot_index = lomuto_partition(array, size, low, high);
		if (pivot_index > 0)
			quick_sort_recursive(array, size, low, pivot_index - 1);
		quick_sort_recursive(array, size, pivot_index + 1, high);
	}
}
/**
* quick_sort - sorts an array of integers in ascending order
* using the quick sort algorithm (Lomuto partition scheme)
* @array: pointer to the array to be sorted
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, size, 0, size - 1);
}


