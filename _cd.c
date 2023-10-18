#include "main.h"

/**
 * _cd - This function.
 * @cmmd: The command from stdin who's path is to be found.
 * @line_num: line number
 * @argv: argument vector
 * Return: void.
 */
int _cd(dou_p cmmd, size_t line_num, dou_p argv)
{
	const char *hm = _getenv("HOME");
	const char *p_wd = _getenv("OLDPWD");

	if (cmmd[1])
	{
		if (p_wd)
		{
			if (!(_strcmp(cmmd[1], "-")))
			{
				if (chdir(p_wd))
					perror("cd");
				return (0);
			}
		}
		else
			perror("cd");

		if (!(chdir(cmmd[1])))
			_error_MESSAGE(argv, line_num, cmmd, "cd");

		return (0);
	}
	else
	{
		if (hm)
		{
			if (chdir(hm))
				perror("cd: HOME");
			return (0);
		}
		else
			perror("cd");
	}
	return (1);
}
