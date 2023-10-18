#include "main.h"

/**
 * _tokenize_slt_exec - Tokenize, parse, execute shell commands ';' and '||'
 * @gtln: The input string to be tokenized and executed
 * @env: An array of environment variables.
 * @av: An array of command-line arguments.
 * @l_dx: The current line number for error reporting.
 * Return: 0 on success, -1 on failure.
 */
int _tokenize_slt_exec(string gtln, dou_p env, dou_p av, size_t l_dx)
{
	dou_p dou_av/*, semi_colon*/ = NULL;

		dou_av = _tokenization(gtln, " \n\t\r");

		if (dou_av && (!(_is_prsent(dou_av[0]))))
		{
			_slt(dou_av[0])(dou_av, l_dx, av);
			/*if (dou_av)*/
			_free(dou_av, 0);
			return (0);
		}

		_execmd(dou_av, env, av, l_dx);

	return (0);
}
