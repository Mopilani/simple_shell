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

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
int _strlen(char *s)
{
	int longi = 0;

	while (*s != '\0')
	{
		longi++;
		s++;
	}

	return (longi);
}

/**
 * _strncmp - Compares string n number of characters into the string.
 * @str1: First string.
 * @str2: Second string.
 * @n: The number of characters to compare.
 * Return: A difference if unequal char and 0 if non found.
 */
int _strncmp(char *str1, char *str2, size_t n)
{
	size_t i = 0;

	while (str1[i] != '\0' && str2[i] != '\0' && i < n)
	{
		if (str1[i] != str2[i])
		{
			return (str1[i] - str2[i]);
		}
		i++;
	}

	return (0);
}

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

/**
 * _strtok - Tokenizer.
 * @str: The string to be tokenized.
 * @_delimiters: String of delimiters foro tokenization.
 * Return: string
 */

string _strtok(string str, string _delimiters)
{
	static string _sStr;
	string _shifter, rv;

	if (str)
		_sStr = str;

	while ((_strchr(_delimiters, *_sStr)) && *_sStr)
	{
		_sStr++;
	}

	if (*_sStr == '\0')
		return (NULL);

	_shifter = _sStr;
	rv = _shifter;

	while (*_shifter)
	{
		if (_strchr(_delimiters, *_shifter))
		{
			if (*_shifter == '\0')
				_sStr = _shifter;
			else
				_sStr = _shifter + 1;

			*_shifter = '\0';

			while (strchr(_delimiters, *_sStr) && *_sStr)
			{
				_sStr++;
			}
			return (rv);
		}
		_shifter++;
	}

	_sStr = _shifter;
	return (rv);
}
