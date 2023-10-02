#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#define SIZE 1024
/**
 * read_textfile - Read text file and print to STDOUT.
 *
 * @filename: The text file being read.
 * @letters: The number of letters to be read.
 *
 * Return: The actual number of bytes read and printed (w).
 *         0 when the function fails or filename is NULL.
 */


ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t total_bytes = 0;
	size_t to_read;
	char buf[SIZE];
	size_t bytes_read;
	size_t bytes_written;
	FILE *ptr;

	if (filename == NULL)
		return (0);


	ptr = fopen(filename, "r");
	if (ptr == NULL)
		return (0);

	while (letters > 0)
	{

		to_read = (letters < SIZE) ? letters : SIZE;

		bytes_read = fread(buf, 1, to_read, ptr);

		if (bytes_read == 0)
			break;

		bytes_written = write(STDOUT_FILENO, buf,  bytes_read);

		if (bytes_written != bytes_read)
			break;
		total_bytes += bytes_written;

		letters -= bytes_written;
	}
	fclose(ptr);
	return (total_bytes);
}
