#include "shell.h"

/**
* _strlen - Returns the length of a string.
* @str: A pointer to the characters string.
*
* Return: The length of the character string.
*/

int _strlen(const char *str)
{
	int length = 0;

	if (!str)
		return (length);

	while (str[length])
	{
		length++;
	}

	return (length);
}

/**
* _strcpy - Copies the string pointed to by src
* @dest: Pointer to the destination of copied string.
* @src: Pointer to the src of the source string.
*
* Return: Pointer to dest.
*/
char *_strcpy(char *dest, const char *src)
{
	size_t i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
* _strcat - Concantenates two strings.
* @dest: Pointer to destination string.
* @src: Pointer to source string.
*
* Return: Pointer to destination string.
*/

char *_strcat(char *dest, const char *src)
{
	char *destTemp;

	const char *srcTemp;

	destTemp = dest;
	srcTemp =  src;

	if (dest != NULL && src != NULL)
	{
		while (*destTemp != '\0')
			destTemp++;

		while (*srcTemp != '\0')
			*destTemp++ = *srcTemp++;
		*destTemp = '\0';
	}

	return (dest);
}

/**
* _strncat - Concantenates two strings where n number
*            of bytes are copied from source.
* @dest: Pointer to destination string.
* @src: Pointer to source string.
* @n: n bytes to copy from src.
*
* Return: Pointer to destination string.
*/

char *_strncat(char *dest, const char *src, size_t n)
{
	size_t dest_len = _strlen(dest);
	size_t h;

	for (h = 0; h < n && src[h] != '\0'; h++)
		dest[dest_len + h] = src[h];
	dest[dest_len + h] = '\0';

	return (dest);
}
