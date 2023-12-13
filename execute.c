#include "shell.h"

/**
* exec_command - Executes a command.
* @cmd: The command to be executed.
*
* Return:
*/

void exec_command(const char *cmd)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		shell_print("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
		else if (child_pid == 0)
	{
		char *args[128];

		int i = 0;

		char *token = strtok((char *)cmd, " ");

		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}
		args[i] = NULL;

		if (args[0] == NULL)
		{
			shell_print("Empty command (Ctrl+D) detected. Exiting.\n");
			exit(EXIT_SUCCESS);
		}

		execvp(args[0], args);

		shell_print("Error executing command.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}
}
