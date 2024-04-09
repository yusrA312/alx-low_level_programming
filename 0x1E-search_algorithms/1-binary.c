#include "search_algos.h"

/**
 * get_midpoint - Function that calculates the midpoint
 * @begin: The starting index of the array segment
 * @end: The ending index of the array segment
 * Return: The calculated midpoint
 */
int get_midpoint(int begin, int end)
{
	return (begin + (end - begin) / 2);
}

/**
 * binary_search - Function that performs a binary search
 * to find the target value
 * @array: The passed in array
 * @size: The size of the given array
 * @value: The target value to be searched for
 * Return: The index of the target value, or -1 if not found
 */
int binary_search(int *array, size_t size, int value)
{
	int begin = 0, end = (int)size - 1;
	int mid = 0, temp = 0;

	if (array == NULL)
		return (-1);

	while (begin <= end)
	{
		temp = begin;
		printf("Searching in array: ");
		while (temp <= end)
		{
			printf("%d", array[temp]);
			if (temp != end)
				printf(", ");
			temp++;
		}
		printf("\n");

		mid = get_midpoint(begin, end);
		if (array[mid] == value)
			return (mid);
		else if (array[mid] < value)
			begin = mid + 1;
		else
			end = mid - 1;
	}

	return (-1);
}
