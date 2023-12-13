#include "shell.h"

/**
* input_command - Reads a command from the standard input
* @command: Pointer to the buffer where the command will be stored
* @size: Size of the buffer
*
* Description: This function reads a command from the standard input
* and stores it in the provided buffer. The function checks for any errors
* while reading and handles them accordingly.
*
* Return: 0 on success, -1 on failure or EOF
*/

int input_command(char *command, size_t size)
{
	if (fgets(command, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			shell_print("\n");
			return (-1);
		}
		else
		{
			shell_print("Error while reading input.\n");
			exit(EXIT_FAILURE);
		}
	}
	command[strcspn(command, "\n")] = '\0';
	return (0);
}
