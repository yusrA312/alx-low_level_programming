#include "search_algos.h"

/**
 * mod_binary_search - Function that performs a binary search
 * to find the target value. A modified version of the
 * binary_search function in 1-binary.c
 * @array: The passed in array
 * @value: The target value to be searched for
 * @begin: The beginning pointer of the array from exponential_search
 * @end: The ending pointer of the array from exponential_search
 * Return: The index of the target value, or -1 if not found
 */
int mod_binary_search(int *array, int value, int begin, int end)
{
	int middle = 0, tempIndex = 0;

	for (; begin <= end; )
	{
		tempIndex = begin;
		printf("Searching in array: ");

		for (; tempIndex <= end; tempIndex++)
		{
			printf("%d", array[tempIndex]);
			if (tempIndex != end)
				printf(", ");
		}

		printf("\n");
		middle = (end + begin) / 2;
		if (array[middle] == value)
			return (middle);
		else if (array[middle] < value)
			begin = middle + 1;
		else
			end = middle - 1;
	}

	return (-1);
}

/**
 * exponential_search - Function that performs an exponential
 * search to find the target value
 * @array: The passed in array
 * @size: The size of the given array
 * @value: The target value to be searched for
 * Return: The index of the target value, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
	int exponent = 1, minimum = 0, maximum;

	if (array == NULL)
		return (-1);

	if (array[0] == value)
		return (0);

	for ( ; exponent < (int)size && array[exponent] < value;)
	{
		printf("Value checked array[%d] = [%d]\n", exponent, array[exponent]);
		exponent *= 2;
	}

	if (exponent + 1 < (int)size)
		minimum = exponent;
	else
		minimum = (int)size - 1;

	printf("Value found between indexes [%d] and [%d]\n", exponent / 2, minimum);
	maximum = exponent / 2;

	return (mod_binary_search(array, value, maximum, minimum));
}
