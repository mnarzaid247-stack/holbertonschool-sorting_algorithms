#include "sort.h"

/**
* quick_sort - sorts an array of integers in ascending order
* using the quick sort algorithm (Lomuto partition scheme)
* @array: pointer to the array to be sorted
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	size_t pivot, j;
	int i, temp;

	if (array == NULL || size < 2)
		return;

	pivot = size - 1;
	i = -1;

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] <= array[pivot])
		{
			i++;
			if (i != (int)j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != (int)pivot)
	{
		temp = array[i + 1];
		array[i + 1] = array[pivot];
		array[pivot] = temp;
		print_array(array, size);
	}
	if (i + 1 > 0)
		quick_sort(array, i + 1);
	if (size - i - 2 > 0)
		quick_sort(array + i + 2, size - i - 2);
}
