#include "main.h"

/**
 * _env - This function prints all environmental variables.
 * Void input and output.
 * @cmmd: command
 * @line_num: line number
 * @argv: argument vector
 * Return: 0
 */
int _env(dou_p cmmd, size_t line_num, dou_p argv)
{
	dou_p dx = environ;

	(void)cmmd;
	(void)argv;
	(void)line_num;

	for (; *dx; dx++)
	{
		_print_string(*dx);
		_putchar('\n');
	}
	return (0);
}
