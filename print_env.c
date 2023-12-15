#include "shell.h"

/**
 * unsetEnvironmentVariable - Unsets the specified environment variable.
 * @variable: The name of the environment variable to be unset.
 *
 * Description: This function unsets the specified environment variable.
 * If unsetting the variable fails, it prints an error message to stderr.
 */

void    unsetEnvironmentVariable(char *variable)
{
        const char      *error_message = "Failed to unset environment variable: ";
        const char      *newline = "\n";

        if (unsetenv(variable) != 0)
        {
                /* Write the error message to stderr character by character*/
                write(STDERR_FILENO, error_message, _strlen(error_message));
                write(STDERR_FILENO, variable, _strlen(variable));
                write(STDERR_FILENO, newline, _strlen(newline));
        }
}
