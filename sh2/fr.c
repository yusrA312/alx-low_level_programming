/**
 * free_all - Frees memory allocated for an array of string
 * @arg: The array of strings to be freed
 *
 * This function takes an array of strings and frees the memory associated with
 * each string within the array, as well as the memory for the array itself.
 */
#include "hsh.h"

void free_all(char **arg)
{int i;
	if (arg == NULL)
		return;

	for (i = 0; arg[i] != NULL; i++)
	{
		free(arg[i]);
	}
	free(arg);
}

