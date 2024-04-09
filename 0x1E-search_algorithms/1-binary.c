#include "search_algos.h"

/**
 * calculate_midpoint - Function that calculates the midpoint
 * @start: The starting index of the array segment
 * @end: The ending index of the array segment
 * Return: The calculated midpoint
 */
int calculate_midpoint(int start, int end)
{
	return (start + (end - start) / 2);
}

/**
 * binary_search - Function that performs a binary search
 * to find the target value
 * @arr: The passed in array
 * @size: The size of the given array
 * @target: The target value to be searched for
 * Return: The index of the target value, or -1 if not found
 */
int binary_search(int *arr, size_t size, int target)
{
	int begin = 0, last = (int)size - 1;
	int mid = 0, tmp = 0;

	if (arr == NULL)
		return (-1);

	while (begin <= last)
	{
		tmp = begin;
		printf("Searching in array: ");
		while (tmp <= last)
		{
			printf("%d", arr[tmp]);
			if (tmp != last)
				printf(", ");
			tmp++;
		}
		printf("\n");

		mid = calculate_midpoint(begin, last);
		if (arr[mid] == target)
			return (mid);
		else if (arr[mid] < target)
			begin = mid + 1;
		else
			last = mid - 1;
	}

	return (-1);
}

