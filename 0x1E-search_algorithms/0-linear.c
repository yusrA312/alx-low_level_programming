#include "search_algos.h"

/**
 * linear_search - Function that performs a linear search
 * to find the target value
 * @array: The passed in array
 * @size: The size of the given array
 * @value: The target value to be searched for
 * Return: The index of the target value, or -1 if not found
 */
int linear_search(int *array, size_t size, int value)
{
	int Yy = 0;

	if (array == NULL)
		return (-1);

	while (Yy < (int)size)
	{
		printf("Value checked array[%d] = [%d]\n", Yy, array[Yy]);
		if (array[Yy] == value)
			return (Yy);

		Yy++;
	}
	return (-1);
}
