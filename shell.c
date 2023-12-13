#include "shell.h"

/**
 * main - Entry point for the program.
 *
 * Return: Always 0.
 */

int main(void)
{
	char command[MAX_CMD_LENGTH];

	while (true)
	{
		display_prompt();
		if (input_command(command, sizeof(command)) == EOF)
		{
			shell_print("");
			 exit(EXIT_SUCCESS);
		}

		if (strcmp(command, "exit") == 0)
		{
			exit_shell();
		}
		else if (strcmp(command, "env") == 0)
		{
			print_env();
		}
		else
		{
			exec_command(command);
		}
	}

	return (0);
}
