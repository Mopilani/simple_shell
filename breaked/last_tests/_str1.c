#include "main.h"

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

/**
 * _print_string - Prints a string on stdout by calling _putchar
 * @st: The string to be written on stdout.
 * Return: Number of chars written on stdout.
 */
int _print_string(string st)
{
	int x, idx;

	for (x = 0; st[x]; x++)
	{
		idx += _putchar(st[x]);
	}
	return (idx);

}
