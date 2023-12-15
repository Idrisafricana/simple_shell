#include "shell.h"

void	startMyshell(void);
/**
 * startMyshell - Initiates the custom shell process.
 *
 * Description: This function starts the custom shell
 * It displays the shell prompt,
 * reads user input, processes commands, and executes them until the user exits
 * the shell. It handles built-in commands such as 'exit', 'env', 'cd',
 *'setenv',
 * and 'unsetenv',
 * as well as executing external commands using executeCommands().
 * It also manages changing directories, setting environment variables,
 * and displays
 * appropriate error messages.
 */
void	startMyshell(void)
{
	char	*prompt = NULL, **args, *envp[] = {NULL};
	size_t	size_prompt;
	ssize_t	numRead;
	int		stat;
	char	*previousDir;
	char	cwd[1024];

	size_prompt = 0;
	stat = 0;
	while (1)
	{

		write(STDOUT_FILENO, "Kel&Afia$ ", 11); /*Display the shell prompt*/

		numRead = getline(&prompt, &size_prompt, stdin); /*Read user input*/
		if (numRead == -1)
		{
			perror("getline");
			free(prompt);
			prompt = NULL;
			exit(EXIT_FAILURE);
		}

		args = funcTokenize(prompt, " \n\t");
		/*Tokenize user input into command arguments*/

		if (args[0])
		{
			if (!_strcmp(args[0], "exit"))
			{
				/* Handle 'exit' command */
				if (args[1])
				{
					stat = _atoi(args[1]);
				}
				else
				{
					free(prompt);
					freeArgs(args);
					exit(stat);
				}
			}
			else if (!_strcmp(args[0], "env"))
			{
				printEnviron();
				stat = 0;
			}
			else if (!_strcmp(args[0], "cd"))
			{
				/* Handle 'cd' command */
				if (args[1] == NULL)
					/* No arguments provided, change to home directory */
					chdir(_getenv("HOME"));
				else if (!_strcmp(args[1], "-"))
				{
					/* Handle "cd -" to change to the previous directory */
					previousDir = _getenv("OLDPWD");
					if (previousDir)
						chdir(previousDir);
				}
				else
				{
					/* Change to the specified directory */
					if (chdir(args[1]) != 0)
						perror("cd");

					else
					{
				/* Update PWD environment variable */
					if (getcwd(cwd, sizeof(cwd)) != NULL)
						setenv("PWD", cwd, 1);
					else
						perror("getcwd");
					}
				}
				stat = 0;
			}
			else if (!_strcmp(args[0], "setenv"))
			{
				/* Handle 'setenv' command */
				if (args[1] && args[2])
				{
					setEnvironmentVariable(args[1], args[2]);
					stat = 0;
				}
				else
				{
					/* Invalid usage of 'setenv' command,display error message */
					write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
					stat = 1;
				}
			}
			else if (!_strcmp(args[0], "unsetenv"))
			{
				/* Handle 'unsetenv' command */
				if (args[1])
				{
					unsetEnvironmentVariable(args[1]);
					stat = 0;
				}
				else
				{
					/* Invalid usage of 'unsetenv' command,display error message */
					write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 25);
					stat = 1;
				}
			}
			else
			{
				/* Execute other commands */
				executeCommands(args, envp, &stat);
			}
		}
		/* Free allocated memory for arguments */
		freeArgs(args);
	}
}
