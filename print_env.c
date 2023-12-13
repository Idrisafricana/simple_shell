#include "shell.h"
#include <stdlib.h>

/**
* print_env - Prints the current environment.
*
* Return: void
*/

void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		shell_print(*env++);
		shell_print("\n");
	}
}
