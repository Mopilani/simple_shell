#include "main.h"

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
