#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers using the bubble sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Description: This function sorts an array of integers in ascending order
 * using the bubble sort algorithm. It repeatedly steps through the list,
 * compares adjacent elements, and swaps them if they are in the wrong order.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int aux;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				aux = array[j];
				array[j] = array[j + 1];
				array[j + 1] = aux;

				print_array(array, size);
			}
		}
	}
}
