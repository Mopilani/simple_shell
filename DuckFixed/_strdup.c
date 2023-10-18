#include "main.h"

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
