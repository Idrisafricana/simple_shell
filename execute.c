include "shell.h"

/**
 * executeCommands - Execute shell commands
 * @args: Array of command arguments
 * @envp: Array of environment variables
 * @stat: Pointer to status variable
 */
void	executeCommands(char **args, char **envp, int *stat)
{
	char	*full_path;
	int		pid;

	full_path = NULL;
	if (access(args[0], X_OK) == 0)
	{
		pid = fork();
		if (pid == 0)
			execve(args[0], args, envp);
		else
			waitChildprocess(stat);
	}
	else if (findFullPath(args[0], &full_path))
	{
		pid = fork();
		if (pid == 0)
			execve(full_path, args, envp);
		else
			waitChildprocess(stat);
		free(full_path);
	}
	else
	{
		*stat = 127;
		writeError(args[0]);
	};
}
