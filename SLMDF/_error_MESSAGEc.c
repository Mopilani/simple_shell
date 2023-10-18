#include "main.h"

/**
 * _error_MESSAGE - Handles the error_MESSAGE of invalid cmmds
 * @argv: Command line argument.
 * @line_num: line number
 * @key_w: to differencite betwwen cd err & addr err
 * @cmmd: Holds the invalid entry.
 * Return: void
 */
void _error_MESSAGE(dou_p argv, size_t line_num, dou_p cmmd, string key_w)
{
	_print_string(argv[0]);
	_print_string(": ");
	_print_num(line_num, 0);
	_print_string(": ");
	_print_string(cmmd[0]); /* sh: 3: cd: can't cd to g */

	if (!(strcmp("cd", key_w)))
	{
		_print_string(": can't cd to ");
		_print_string(cmmd[1]);
	}
	else
		_print_string(": not found");

	_putchar('\n');
}
