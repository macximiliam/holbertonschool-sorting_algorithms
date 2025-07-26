#include "sort.h"


/**
 * lomuto - Lomuto partition scheme for Quick Sort
 * @array: Pointer to the array of integers to be sorted
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @size: Total size of the array
 *
 * Return: The index of the pivot after partitioning
 *
 * Description: Partitions the array around a pivot, placing elements smaller
 * than or equal to the pivot on the left, and larger elements on the right.
 */
int lomuto(int *array, int low, int high, size_t size)
{
	int pivot;
	int i, j, temp;

	pivot = array[high];
	i = low;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;

			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, size);

	return (i + 1);
}
/**
 * quick_sort_recursive - Recursively applies Quick Sort
 * @array: Pointer to the array of integers to be sorted
 * @low: Starting index of the subarray
 * @high: Ending index of the subarray
 * @size: Total size of the array
 *
 * Description: Recursively partitions and sorts the subarrays until sorted.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = lomuto(array, low, high, size);
		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - Entry point for Quick Sort algorithm
 * @array: Pointer to the array of integers to be sorted
 * @size: Total size of the array
 *
 * Description: Validates the array and starts the recursive sorting process.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
