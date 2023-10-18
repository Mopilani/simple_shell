#include "main.h"

/**
 * _strcmp - Compares two string.
 * @str: First string.
 * @_str: Second string.
 * Return: A difference if unequal char and 0 if non found.
 */
int _strcmp(char *str, char *_str)
{
	int i = 0;

	while (str[i] != '\0' && _str[i] != '\0')
	{
		if (str[i] != _str[i])
		{
			return (str[i] - _str[i]);
		}
		i++;
	}

	return (0);
}
