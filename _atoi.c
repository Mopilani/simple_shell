#include "shell.h"

/**
 * int_act - return true if shell is int_act mode
 * @info: struct address
 *
 * Return: 1 if int_act mode, 0 otherwise
 */
int int_act(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_del -  if character is a delimeter
 * @chck: the char to check
 * @del: the delimeter string
 * Return: 1 if true, else 0  [false]
 */
int is_del(char chck, char *del)
{
	while (*del)
		if (*del++ == chck)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@input_char: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int input_char)
{
	if ((input_char >= 'a' && input_char <= 'z') ||
	(input_char >= 'A' && input_char <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@convert_to_string: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *convert_to_string)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  convert_to_string[i] != '\0' && flag != 2; i++)
	{
		if (convert_to_string[i] == '-')
			sign *= -1;

		if (convert_to_string[i] >= '0' && convert_to_string[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (convert_to_string[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
