#include "search_algos.h"


/**
 * linear_search_range - Searches for a value in a range using linear search
 * @array: A pointer to the first element of the array to search.
 * @start: The starting index of the range.
 * @end: The ending index of the range.
 * @value: The value to search for.
 *
 * Return: If the value is not present, -1.
 *         Otherwise, the index where the value is located.
 */
int linear_search_range(int *array, size_t start, size_t end, int value)
{
	size_t i;

	for (i = start; i <= end; i++)
	{
		printf("Value checked array[%ld] = [%d]\n", i, array[i]);
		if (array[i] == value)
			return ((int)i);
	}
	return (-1);
}

/**
 * jump_search - Searches for a value in a sorted array using jump search
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the first index where the value is located.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t i, jump;
	size_t step = sqrt(size);
	int result;

	if (array == NULL || size == 0)
		return (-1);


	for (i = jump = 0; jump < size && array[jump] < value;)
	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		i = jump;
		jump += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", i, jump);

	jump = jump < size - 1 ? jump : size - 1;

	result = linear_search_range(array, i, jump, value);
	if (result != -1)
		return (result);

	{
		printf("Value checked array[%ld] = [%d]\n", jump, array[jump]);
		return (-1);
	}
}
