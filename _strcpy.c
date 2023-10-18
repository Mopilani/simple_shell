#include "main.h"

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
