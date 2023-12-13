#include "shell.h"

/**
* exit_shell - Exits the shell.
*
* Return: void
*/

void exit_shell(void)
{
	shell_print("Exiting the shell.\n");
	exit(EXIT_SUCCESS);
}
