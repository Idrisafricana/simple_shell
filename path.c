#include "shell.h"

/**
 * findFullPath - Find the full path of a command
 * @prompt: Command prompt
 * @full_path: Pointer to store full path
 * Return: 1 if found, 0 otherwise
 */

int	findFullPath(char *prompt, char **full_path)
{
	int		found;
	char	*path_env_copy;

	char *token, *path_env;

	found = 0;
	path_env = _getenv("PATH");
	if (path_env != NULL)
	{
		path_env_copy = strdup(path_env);
		token = strtok(path_env_copy, ":");
		while (token != NULL && !found)
		{
			*full_path = malloc(strlen(token) + strlen(prompt) + 2);
			if (*full_path != NULL)
			{
				strcpy(*full_path, token);
				strcat(*full_path, "/");
				strcat(*full_path, prompt);
				if (access(*full_path, X_OK) == 0)
				{
					found = 1;
				}
				if (!found)
					free(*full_path);
			}
			token = strtok(NULL, ":");
		}
		free(path_env_copy);
	}
	return (found);
}
