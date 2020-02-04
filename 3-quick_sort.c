#include "sort.h"
/**
 * sort - Sorting algorithim with recursion
 * @array: Array to be sorted
 * @size: Amount of elements in the array
 * @start: The start of the array
 * @end: The end of the array
 * Return: No return
 */
void sort(int *array, size_t size, int start, int end)
{
	int p = array[end], i = start, j, temp;

	if (end - start < 2)
		return;

	for (j = start; j < end; j++)
	{
		if (array[j] < p)
		{
			if (array[j] != array[i])
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (p < array[i])
	{
		temp = array[i];
		array[i] = p;
		array[end] = temp;

		if (i != j)
			print_array(array, size);
	}
	if (i == 0)
		sort(array, size, 1, end);
	else
	{
		sort(array, size, start, i - 1);
		sort(array, size, i + 1, end);
	}
}



/**
 * quick_sort - Sorting algorithim by selection
 * @array: Array to be sorted
 * @size: Amount of elements in the array
 * Return: No return
 */

void quick_sort(int *array, size_t size)
{
	if (array != NULL && size > 1)
		sort(array, size, 0, size - 1);
}
