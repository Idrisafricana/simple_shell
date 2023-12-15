#include "shell.h"

char **_copyenv(void);
void free_env(void);
char **_getenv(const char *var);

/**
 * _copyenv - Creates a copy of the environment.
 *
 * Return: If an error occurs - NULL.
 *         O/w - a double pointer to the new copy.
 */
char **_copyenv(void)
{
	char **new_environ;
	size_t size;
	int j;

	for (size = 0; environ[size]; size++)
		;

	new_environ = malloc(sizeof(char *) * (size + 1));
	if (!new_environ)
		return (NULL);

	for (j = 0; environ[j]; j++)
	{
		new_environ[j] = malloc(_strlen(environ[j]) + 1);

		if (!new_environ[j])
		{
			for (j--; j >= 0; j--)
				free(new_environ[j]);
			free(new_environ);
			return (NULL);
		}
		_strcpy(new_environ[j], environ[j]);
	}
	new_environ[j] = NULL;

	return (new_environ);
}

/**
 * free_env - Frees the memory allocated
 * for the environment variables.
 *
 * Return: NULL.
 */

void free_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
		free(environ[i]);
	free(environ);
}

/**
 * _getenv - Gets an environmental variable from the PATH.
 * @var: The name of the environmental variable to get.
 *
 * Return: If the environmental variable does not exist - NULL.
 *         Otherwise - a pointer to the environmental variable.
 */
char **_getenv(const char *var)
{
	int k, len;

	len = _strlen(var);
	for (k = 0; environ[k]; k++)
	{
		if (_strncmp(var, environ[k], len) == 0)
			return (&environ[k]);
	}

	return (NULL);
}
