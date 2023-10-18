#include "main.h"
/**
 * _strncpy - copy 'n' num of memory form src to dest.
 * @dest: mem to be cpied to.
 * @src: mem to be copied from.
 * @n: Num of mem to be copied from src.
 * Return: copy of src in dest with padding of '\0'
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t j = 0;

	/* Copy from 'src' to 'dest' up to 'n' or until the \0 is encountered. */
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}

	/* If 'n' is greater > length of 'src', pad 'dest' with null characters. */
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}

	return (dest);
}
