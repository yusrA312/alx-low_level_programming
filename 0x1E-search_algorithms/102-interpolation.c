#include "search_algos.h"

/**
 * calculate_pos - Calculates the position for interpolation search
 *
 * @l: The lower index of the array.
 * @h: The higher index of the array.
 * @v: The value to search for.
 * @arr: A pointer to the first element of the array.
 *
 * Return: The calculated position.
 */
size_t calculate_pos(size_t l, size_t h, int v, int *arr)
{
	return (l + (((double)(h - l) / (arr[h] - arr[l])) * (v - arr[l])));
}


/**
 * interpolation_search - Searches for a value in a sorted array of
 * integers using the Interpolation search algorithm.
 *
 * @array: A pointer to the first element of the array to search in.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: The first index where value is located or -1 if not found.
 */
int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1;

	if (!array)
		return (-1);

	for (; low <= high;)
	{
		size_t pos = calculate_pos(low, high, value, array);


		if (pos >= size)
		{
			printf("Value checked array[%ld] is out of range\n", pos);
			break;
		}

		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);

		if (array[pos] == value)
			return (pos);
		else if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}

	return (-1);
}
