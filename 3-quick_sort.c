#include "sort.h"
/**
* quick_sort - sorts an array of integers in
* ascending order using the quick sort algorithm
* @array: pointer to the array to be sorted
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	size_t pivot = size - 1;
	unsigned int i = -1;

	size_t j = 0;
	int temp;

	if (array == NULL || size < 2)
		return;
for (; j < size - 1; j++)
{
	if (array[j] <= array[pivot])
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
}
	temp = array[i + 1];
	array[i + 1] = array[pivot];
	array[pivot] = temp;
	print_array(array, size);
	if (i + 1 > 0)
		quick_sort(array, i + 1);
	if (size - i - 2 > 0)
		quick_sort(array + i + 2, size - i - 2);
}
