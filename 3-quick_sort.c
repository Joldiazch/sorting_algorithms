#include "sort.h"
/**
 * quick_sort - Sorting algorithim by selection
 * @array: Array to be sorted
 * @size: Amount of elements in the array
 * Return: No return
 */

void sort(int *array, size_t size, size_t i, size_t j)
{
	int p = array[size - 1], temp = 0;
	if (size < 3)
		return;

	for (j = 0; j < size - 1; j++)
	{
		if (array[j] < p)
		{
			if (array[i] != array[j])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}

	temp = array[i];
	array[i] = p;
	array[size - 1] = temp;

	print_array(array, size);

	sort(array, size -1, i + 1, j);
}
void quick_sort(int *array, size_t size)
{
	sort(array, size, 0, 0);
}
