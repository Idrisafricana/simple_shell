#include "shell.h"

/**
 * custom_strcpy - Custom implementation of strcpy.
 * @dest: Destination string.
 * @src: Source string.
 *
 * Return: Pointer to the destination string.
 */
char *custom_strcpy(char *dest, const char *src)
{
    char *result = dest;

    if (dest == NULL || src == NULL)
        return NULL;

    while ((*dest++ = *src++) != '\0')
        ;

    return result;
}
