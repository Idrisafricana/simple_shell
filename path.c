#include "shell.h"

/**
* build_full_path - Builds the full path for a given command.
* @command: The command to build the full path for.
* @full_path: Buffer to store the full path.
*
* Return: 1 on success, 0 on failure.
*/
int build_full_path(const char *command, char *full_path)
{
	char *path = getenv("PATH");

	char *token = strtok(path, ":");

	while (token != NULL)
	{
		custom_snprintf(full_path, MAX_PATH_LENGTH, "%s/%s", token, command);
		if (access(full_path, X_OK) == 0)
		{
			return (1);
		}

		token = strtok(NULL, ":");
	}

	return (0);
}
