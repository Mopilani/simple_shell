#include "main.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *src)
{
	int j = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[j])
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str_dup: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str_dup)
{
	int length = 0;
	char *ret;

	if (str_dup == NULL)
		return (NULL);
	while (*str_dup++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str_dup;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str_print: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str_print)
{
	int i = 0;

	if (!str_print)
		return;
	while (str_print[i] != '\0')
	{
		_putchar(str_print[i]);
		i++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @char_print: The character to print
 *
 * Return: 1 if success.
 * On error, -1 is returned, and errno .
 */
int _putchar(char char_print)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (char_print == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (char_print != BUF_FLUSH)
		buf[i++] = char_print;
	return (1);
}
