#include "main.h"

/**
 * _strcat - Concatenates two strings strcat()
 *
 * @dest: The destination string to which src will be appended.
 * @src: The source string that will be appended to dest.
 *
 * Return: A pointer to the modified dest string.
 */

string _strcat(string dest, string src)
{
	int i = 0, j = 0;

	i = _strlen(dest);

	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';

	return (dest);
}

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

/**
 * _strcpy - copy a string from 'src' to 'dest'
 * @dest: destination string
 * @src: source string
 * Return: Pointer to 'dest'.
 */
string _strcpy(string dest, string src)
{
	int z = 0, x = 0;

	z = _strlen(src);

	for (; x < z; x++)
		dest[x] = src[x];

	dest[z] = '\0';
	return (dest);
}

/**
 * _strdup - uses malloc to alloc memory.
 *
 * @str: input string.
 * Return: A pointer to the new memory allocation.
 */

char *_strdup(string str)
{
	char *b;
	size_t idx, m;

	if (str == NULL)
		return (0);

	idx = _strlen(str);

	b = malloc((idx + 1) * sizeof(char));
	if (b == NULL)
		return (0);

	for (m = 0; m < idx; m++)
		b[m] = str[m];

	b[m] = '\0';

	return (b);
}

