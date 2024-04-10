#include "search_algos.h"

/**
 * exponential_search - Searches for a value in a sorted array
 *                      of integers using exponential search.
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 *
 * Description: Prints a value every time it is compared in the array.
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t start, end, i, j, mid;

	if (array == NULL)
		return (-1);

	start = 0;
	end = size - 1;

	if (array[start] == value)
		return (start);

	for (i = 1; i < size && array[i] <= value; i *= 2)
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);

	printf("Value found between indexes [%ld] and [%ld]\n", i / 2, end);

	while (end >= i / 2)
	{
		printf("Searching in array: ");
		for (j = i / 2; j < end; j++)
			printf("%d, ", array[j]);
		printf("%d\n", array[end]);

		mid = i / 2 + (end - i / 2) / 2;
		if (array[mid] == value)
		{
			printf("Found %d at index: %ld\n", value, mid);
			return (mid);
		}
		if (array[mid] > value)
			end = mid - 1;
		else
			start = mid + 1;
	}

	printf("Found %d at index: -1\n", value);
	return (-1);
}
