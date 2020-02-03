#include "sort.h"
/**
 * bubble_sort - Sorting algorithim by selection
 * @array: Array to be sorted
 * @size: Amount of elements in the array
 * Return: No return
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, a = size, n = size, tem = 0;

	if (size >= 2)
	{
		size--;
		while (a != 0)
		{
			for (i = 0; i + 1 <= size; i++)
			{
				if (array[i] > array[i + 1])
				{
					tem = array[i];
					array[i] = array[i + 1];
					array[i + 1] = tem;
					print_array(array, n);
				}
			}
			a = size--;
			i = 0;
		}
	}
}
