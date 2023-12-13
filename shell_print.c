#include "shell.h"

/**
 * shell_print - Print to standard output.
 * @string: string that points to the characters.
 *
 *  Return: void
 */

void shell_print(const char *string)
{
	write(STDOUT_FILENO, string, strlen(string));
}
