#include "search_algos.h"
/**
 * jump_search - Searchesa value in a sorted array using jump search algorithm
 * @array: A pointer to the first element of the array to search.
 * @size: The number of elements in the array.
 * @value: The value to search for.
 *
 * Return: If the value is not present or the array is NULL, -1.
 *         Otherwise, the index where the value is located.
 */
int jump_search(int *array, size_t size, int value)
{
	size_t left = 0, right = 0, step = 0;

	if (array == NULL || size == 0)
		return (-1);

	step = sqrt(size);

	while (right < size && array[right] < value)
	{
		printf("Value checked array[%ld] = [%d]\n", right, array[right]);
		left = right;
		right += step;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", left, right);

	right = right < size ? right : size - 1;

	while (left <= right)
	{
		printf("Value checked array[%ld] = [%d]\n", left, array[left]);
		if (array[left] == value)
			return (left);
		left++;
	}

	return (-1);
}
