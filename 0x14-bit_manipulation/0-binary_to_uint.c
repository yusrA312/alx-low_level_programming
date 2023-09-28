#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	int i, num, rem, x, base = 1, n;
	int int_num = 0;

	x = strlen(b);
	num = atoi(b);

	if (!b)
		return (0);

	for (n = 0; b[n]; n++)
	{

		if (b[n] < '0' || b[n] > '1')
			return (0);
	}

	for (i = x - 1; i >= 0; i--)
	{rem = num % 10;
		int_num = int_num + rem * base;
		num = num / 10;
		base = base * 2;
	}
	return (int_num);
}
