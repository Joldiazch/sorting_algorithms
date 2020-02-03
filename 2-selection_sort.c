#include "sort.h"
/**
 * selection_sort - Sorting algorithim by selection
 * @array: Array to be sorted
 * @size: Amount of elements in the array
 * Return: No return
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j = 0, index;
	int min = 0, flag = 0;

	for (i = 0; i < size && array != NULL; i++)
	{
		min = array[i];
		for (j = i; j < size; j++)
		{
			if (array[j] < min)
			{
				min = array[j];
				index = j;
				flag = 1;
			}
		}
		array[index] = array[i];
		array[i] = min;
		if (flag == 1)
		{
			print_array(array, size);
			flag = 0;
		}
	}
}
