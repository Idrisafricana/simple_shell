#include "shell.h"


/**
 * custom_snprintf - Custom implementation of snprintf.
 * @str: Buffer to store the formatted string.
 * @size: Maximum number of characters to be written.
 * @format: Format string.
 * @...: Additional arguments.
 *
 * Return: Number of characters written (excluding the null terminator),
 * or a negative value if an error occurred.
 */
int custom_snprintf(char *str, size_t size, const char *format, ...)
{
    va_list args;
    int result;

    if (str == NULL || format == NULL)
        return -1;

    va_start(args, format);
    result = vsnprintf(str, size, format, args);
    va_end(args);

    return result;
}
