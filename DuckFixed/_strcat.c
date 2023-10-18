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

