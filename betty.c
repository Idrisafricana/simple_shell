#include <unistd.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
    char message[] = "Simple shell project\n";

    write(STDOUT_FILENO, message, sizeof(message) - 1);

    return (0);
}
