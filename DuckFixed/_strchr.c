#include "main.h"

/**
 * _strchr - Entry point
 * @s: input
 * @c: input
 * Return: A pointer to the first occurrence of
 * character 'c' in the string 's', or NULL if 'c' is not found.
 */
int _strchr(char *s, char c)
{
	int i = 0;

	for (; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			return (1);
	}

	return (0);
}
