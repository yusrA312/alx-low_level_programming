#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#define SIZE 1024

/**
 * error - Display an error message and exit the program with an error code.
 *
 * @M: The error message to display.
 * @ex: The exit code to use when exiting the program.
 *
 * Error Codes:
 *  - 97: Incorrect usage. Should be "cp file_from file_to".
 *  - 98: Failed to read from the source file.
 *  - 99: Failed to write to the destination file.
 *  - 100: Failed to close a file descriptor.
 */

void error(const char *M, int ex)
{
	dprintf(STDERR_FILENO, "Error: %s\n", M);
	exit(ex);
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, or an error code (97, 98, 99, or 100) on failure.
 *
 * Description:
 * This program takes two command-line arguments: the source file (file_from)
 * and the destination file (file_to). It copies the content of the source
 * file to the destination file while handling various error conditions.
 */

int main(int argc, char *argv[])
{
	int ptr_to;
	const char *file_from;
	const char *file_to;
	ssize_t re, wr;
	int ptr_from;
	char buf[SIZE];

	if (argc != 3)
		error("Usage: cp file_from file_to", 97);
	file_from = argv[1];
	file_to = argv[2];
	ptr_from = open(file_from, O_RDONLY);
	if (ptr_from == -1)
		error("Can't read from file", 98);
	ptr_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (ptr_to == -1)
	{
		close(ptr_from);
		error("Can't write to file", 99);
	}
	while ((re = read(ptr_from, buf, SIZE)) > 0)
	{
		wr = write(ptr_to, buf, re);
		if (wr != re || wr == -1)
		{
			close(ptr_from);
			close(ptr_to);
			error("Can't write to file", 99);
		}
	}
	if (re == -1)
	{
		close(ptr_from);
		close(ptr_to);
		error("Can't read from file", 98);
	}
	if (close(ptr_from) == -1 || close(ptr_to) == -1)
		error("Can't close ptr", 100);
	return (0);

}
