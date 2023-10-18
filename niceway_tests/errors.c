#include "shell.h"

/**
 *_input_str - prints an input string
 * @ptr_str: the string to be printed
 *
 * Return: Nothing
 */
void _input_str(char *ptr_str)
{
	int i = 0;

	if (!ptr_str)
		return;
	while (ptr_str[i] != '\0')
	{
		_putchar(ptr_str[i]);
		i++;
	}
}

/**
 * _wrt_errr - writes the char to stderr
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, return -1 , and errno is set appropriately.
 */
int _wrt_errr(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @ptr_str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *ptr_str, int fd)
{
	int i = 0;

	if (!ptr_str)
		return (0);
	while (*ptr_str)
	{
		i += _putfd(*ptr_str++, fd);
	}
	return (i);
}
