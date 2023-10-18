#include "main.h"

/**
 * _unsetenv - Function to set or update an environment variable
 * @dou_argv: [0] Name of the environment variable
 * [1] Value to assign to the environment variable.
 * @argv: UNUSED argument vector.
 * @line_num: UNUSED line count.
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(dou_p dou_argv, size_t line_num, dou_p argv)
{

	char *name = dou_argv[1]/*, *tmp = NULL*/;
	char **env = environ;
	int x = 0;

	(void)line_num;
	(void)argv;
	if (name == NULL)   /* Invalid input OR Mem err */
	{
		perror("unsetenv VARIABLE");
		return (-1);
	}
	for (; *env; x++, env++)   /* If overwrite is 1, replace existing variable */
	{
		if (!(_strncmp(name, *env, _strlen(name))))   /* Replace existing variable */
		{
			for (; environ[x]; x++)
			{
				environ[x] = environ[x + 1];
			}

			free(*env);
			return (0);
		}
	}
	return (-1);
}


