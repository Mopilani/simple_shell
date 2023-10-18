#include "main.h"

/**
 * _slt - Loops & compares 's' with the struct 'key_w'
 * @s: The string to be compared with 'key_w'
 * Return: A function pointer if found, otherwise returns 0
 */
int (*_slt(string s))(dou_p dou_argv, size_t line_num, dou_p argv)
{
	int x;

	_is fmt[] = {
		{"cd", &_cd},
		{"env", &_env},
		{"exit", &_exit_num},
		{"setenv", &_setenv},
		{"unsetenv", &_unsetenv},
		{'\0', NULL},
	};

	for (x = 0; fmt[x].key_w; x++)
	{
		if (!(_strcmp(s, fmt[x].key_w)))
			return (fmt[x]._func);
	}
	return (0);
}
