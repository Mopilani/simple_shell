#include "main.h"

/**
 * main - Simple_Shell main function.
 * @ac: args count.	
 * @argv: passed args double pointer.
 * @env: Environmental variable.
 * Return: returns 0 on success.
 */
int main(int ac, dou_p argv, dou_p env)
{
	size_t bffsz, line_num = 1;
	string getline_ptr = NULL;
	/*dou_p dou_argv, semi_colon;*/

	(void)ac;
	while (GERRY)
	{
		if (isatty(STDIN_FILENO))
			_print_string("$ ");

		if ((getline(&getline_ptr, &bffsz, stdin)) == EOF)	/* ctrl D */
		{
			_free(getline_ptr, 0);
			_putchar('\n');
			exit(ERROR);
		}

		if (!(_strcmp(getline_ptr, "\n"))) /* Handles New line */
		{
			/*_free(getline_ptr, 0);*/
			line_num++;
			continue;
		}

		_tokenize_slt_exec(getline_ptr, env, argv, line_num);


		if (!(isatty(STDIN_FILENO)))
			break;
	}
	/*free(getline_ptr);*/
	return (0);
}
