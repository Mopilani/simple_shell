#include "main.h"

/**
 * _convrt_str_to_int - converts a string to an integer
 * @convrt_str: the string to be converted
 * Return: 0 if (numbers) in string, converted number otherwise
 *       -1 on err
 */
int _convrt_str_to_int(char *convrt_str)
{
	int i = 0;
	unsigned long int result = 0;

	if (*convrt_str == '+')
		convrt_str++;  /* TODO: why does this make main return 255? */
	for (i = 0;  convrt_str[i] != '\0'; i++)
	{
		if (convrt_str[i] >= '0' && convrt_str[i] <= '9')
		{
			result *= 10;
			result += (convrt_str[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_err - prints  error msg
 * @info: the parameter & return info struct
 * @estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_err(info_t *info, char *estr)
{
	_input_str(info->fname);
	_input_str(": ");
	print_d(info->line_count, STDERR_FILENO);
	_input_str(": ");
	_input_str(info->argv[0]);
	_input_str(": ");
	_input_str(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _putchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + current / i);
			count++;
		}
		current %= i;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flg: argument flag
 *
 * Return: str
 */
char *convert_number(long int num, int base, int flg)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flg & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flg & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buffer: address of the string to modify
 *
 * Return: 0;
 */
void remove_comments(char *buffer)
{
	int i;

	for (i = 0; buffer[i] != '\0'; i++)
		if (buffer[i] == '#' && (!i || buffer[i - 1] == ' '))
		{
			buffer[i] = '\0';
			break;
		}
}
