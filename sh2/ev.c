#include "hsh.h"

/**
 * envi -handles the env built-in command
 *@env_word: Arguments for the env command
 *Return: Nothing
 */

int envi(char **env_word)
{ char **ptr;

	ptr = environ;

	if (!env_word[1])
	{
		while (*ptr)
		{
			write(STDOUT_FILENO, *ptr, _strlen(*ptr));
			write(STDOUT_FILENO, "\n", 1);
			ptr++; }
		return (-1);  }
	return (-1); }
	/**
	 *in_env - gets the value of a speficied environment variable
	 * @in_env: Variable to look for in environment
	 * Return: Pointer to start index of the value.
	 */

char *in_env(char *in_env)
{
	char **ptr = environ;
	int len = _strlen(in_env);

	while (*ptr)
	{

		if (_strncmp(*ptr, in_env, len) == 0 && (*ptr)[len] == '=')
		{
			return (&((*ptr)[len + 1]));
		}
		ptr++;
	}
	return (NULL);
}

