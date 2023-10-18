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
		
		_print_string("Hello world");
		dou_av = _tokenization(gtln, " \n\t\r");
		_print_string("No hello world");
		if (dou_av && (!(_is_prsent(dou_av[0]))))
		{
			_slt(dou_av[0])(dou_av, l_dx, av); /*if (dou_av)*/
			_free(dou_av, 0);
			return (0);
		}
		else
		{
			_print_string("Double Not Found");
		}

		_execmd(dou_av, env, av, l_dx);

	return (0);
}


/**
 * _tokenization - Takes the string from stdin and tokenize into dou_p
 * @str: The string to be tokenized.
 * @_delimiters: The string of delimiters for parsing.
 * Return: A Double pointer.
 *
 */
dou_p _tokenization(string str, string _delimiters)
{
	string token;
	int i = 0, _idx = 0;
	dou_p local_argv;

	i = 0;
	while (str[_idx] != '\0')
	{
		if (_strchr(_delimiters, str[_idx]))
			i++;
		_idx++;
	}
	local_argv = malloc(sizeof(char *) * (i + 1));

	token = _strtok(str, _delimiters);

	_idx = 0;
	while (token != NULL)
	{
		local_argv[_idx] = token;
		_idx++;
		token = _strtok(NULL, _delimiters);
	}
	local_argv[_idx] = NULL;

	return (local_argv);
}
