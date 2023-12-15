#include "shell.h"

/**
 * nonInteractMode - Executes shell commands,
 *  in non-interactive mode.
 * @token: User input token containing the command.
 * @status: Pointer to the status variable indicating,
 * the command's exit status.
 *
 * Description: This function handles shell commands
 * provided in non-interactive mode.
 * It tokenizes the input command, processes built-in functions
 * such as 'exit', 'env',
 * 'cd', 'setenv', and 'unsetenv', or executes
 * external commands using executeCommands().
 * The function also handles changing directories,
 *  setting environment variables, and
 * displaying appropriate error messages.
 */
void	nonInteractMode(char *token, int *status)
{
	char	**single_command;
	char	*envp[] = {NULL};
	char	*previousDir;
	char	cwd[1024];

	token[_strlen(token) - 1] = '\0';
	single_command = funcTokenize(token, " \t");
	if (single_command[0])
	{
		if (!_strcmp(single_command[0], "exit"))
		{
			if (single_command[1])
			{
				*status = _atoi(single_command[1]);

			}
			free(token);
			freeArgs(single_command);
			exit(*status);
		}
		else if (!_strcmp(single_command[0], "env"))
		{
			printEnviron();
			*status = 0;
		}
		else if (!_strcmp(single_command[0], "cd"))
		{
			/* Handle cd command */
			if (single_command[1] == NULL)
			{
				/* No arguments provided, change to home directory */
				chdir(_getenv("HOME"));
			}
			else if (!_strcmp(single_command[1], "-"))
			{
				/* Handle "cd -" to change to the previous directory */
				previousDir = _getenv("OLDPWD");
				if (previousDir)
				{
					chdir(previousDir);
				}
			}
			else
			{
				/* Change to the specified directory */
				if (chdir(single_command[1]) != 0)
				{
					perror("cd");
				}
				else
				{
					/* Update PWD environment variable */
					if (getcwd(cwd, sizeof(cwd)) != NULL)
					{
						setenv("PWD", cwd, 1);
					}
					else
					{
						perror("getcwd");
					}
				}
			}
			*status = 0; /* Set status to success for cd command */
		}
		else if (!_strcmp(single_command[0], "setenv"))
		{
			if (single_command[1] && single_command[2])
			{
				setEnvironmentVariable(single_command[1], single_command[2]);
				*status = 0;
			}
			else
			{
				write(STDERR_FILENO, "Usage: setenv VARIABLE\n", 29);
				*status = 1;
			}
		}
		else if (!_strcmp(single_command[0], "unsetenv"))
		{
			if (single_command[1])
			{
				unsetEnvironmentVariable(single_command[1]);
				*status = 0;
			}
			else
			{
				write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
				*status = 1;
			}
		}
		else
		{
			executeCommands(single_command, envp, status);
		}
	}
	freeArgs(single_command);
}
