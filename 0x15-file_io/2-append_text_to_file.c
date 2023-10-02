#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * append_text_to_file - Append text to the end of a file.
 *
 * @filename: The name of the file to which text will be appended.
 * @text_content: The text content to append to the file
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int w, len = 0, p;

	if (filename == NULL)
		return (-1);

	p = open(filename, O_WRONLY | O_APPEND);

	if (p == -1)
		return (-1);

	if (text_content != NULL)
	{		len = strlen(text_content);

		w = write(p, text_content, len);
	}

	if (w == -1)
		return (-1);

	close(p);

	return (1);
}
