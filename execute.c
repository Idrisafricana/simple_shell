#include "shell.h"

/**
* exec_command - Executes a command with arguments.
* @cmd: The command to be executed.
*
* Return: void
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
		execute_child(cmd);
	}
	else
	{
		wait(NULL);
	}
}

/**
* execute_child - Executes the command in the child process.
* @cmd: The command to be executed.
*
* Return: void
*/

void execute_child(const char *cmd)
{
	char *args[MAX_CMD_LENGTH];

	char full_path[MAX_PATH_LENGTH];

	int i = 0;

	char *token = strtok((char *)cmd, " ");

<<<<<<< HEAD
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
=======
		execve(args[0], args);

		perror("execve");
		shell_print("Error executing command.\n");
		exit(EXIT_FAILURE);
>>>>>>> a8d6c13090e62327a570890747db745b83f8c9d4
	}

	custom_strcpy(full_path, "");

	if (!build_full_path(args[0], full_path))
	{
		shell_print("Command not found.\n");
		exit(EXIT_FAILURE);
	}

	execve(full_path, args, environ);

	perror("execve");
	shell_print("Error executing command.\n");
	exit(EXIT_FAILURE);
}
