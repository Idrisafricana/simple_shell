#include "shell.h"

/**
* token_command - Tokenizes a command and its arguments.
* @cmd: The command to be tokenized.
* @args: An array to store the tokenized command and its arguments.
*
* Return: The number of arguments.
*/
int token_command(const char *cmd, char *args[])
{
	char *token;
	int i = 0;

	token = strtok((char *)cmd, " ");

	while (token != NULL)
	{
		args[i++] = token;
		token = strtok(NULL, " ");
	}

	args[i] = NULL;

	return (i);
}
