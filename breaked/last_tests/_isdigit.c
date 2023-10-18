#include "main.h"

/**
 * _isdigit - Checks if a character represents a digit (0-9).
 * @c: The character to be checked.
 * Return: 1 if @c is a digit, 0 otherwise.
 */

int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);

	return (0);
}
