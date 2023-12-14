#include "shell.h"

/**
* custom_strcmp - Custom implementation of strcmp.
* @str1: The first string to compare.
* @str2: The second string to compare.
*
* Return: string to compare
*/
int custom_strcmp(const char *str1, const char *str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}
	return (*(unsigned char *)str1 - *(unsigned char *)str2);
}
