#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
*create_file-Create a file with specified name and write
 *
 * @filename: The name of the file to be created.
 * @text_content: The text content to write to the file
 *
 * Return: 1 on success, -1 on failure .
 *         The created file has permissions: rw-------.
 * If the file already exists, it will be truncated to contain the new content.
 *         If filename is NULL, return -1.
 *         If text_content is NULL, create an empty file.
 */

int create_file(const char *filename, char *text_content)

{

	int f;
	int x;


	if (filename == NULL)

		return (-1);

	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	x = write(f, text_content, strlen(text_content));


	if (f == -1 || x == -1)

		return (-1);


	close(f);


	return (1);

}
