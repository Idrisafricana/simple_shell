#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 on Success
 */

int main(void)
{
	const char message[] = "Simple shell project\n";

	for (int i = 0; message[i] != '\0'; ++i)
	{
	write(STDOUT_FILENO, &message[i], 1);
	}

	return (0);
}
