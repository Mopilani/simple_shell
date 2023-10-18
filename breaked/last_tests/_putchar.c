#include "main.h"

/**
 * _putchar - Puts a character on stdout.
 * @c: The char to be written on stdout.
 * Return: Number of chars written = 1.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1)); /* STDOUT_FILENO is part of unistd.h */
}
