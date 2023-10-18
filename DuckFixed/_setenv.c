#include "main.h"

/**
 * _setenv - Function to set or update an environment variable
 * @dou_argv: [0] Name of the environment variable
 *              [1] Value to assign to the environment variable.
 * @argv: UNUSED argument vector.
 * @line_num: UNUSED line count.
 * Return: 0 on success, -1 on failure
 */
int _setenv(dou_p dou_argv, size_t line_num, dou_p argv)
{

	char *name = dou_argv[1];
	char *value = dou_argv[2];
	char **env = environ;
	/* +2 for '=' and null terminator */
	char *new_var = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
	int dx = 0;

	(void)line_num;
	(void)argv;
	if (name == NULL || value == NULL || new_var == NULL)
	{
		if (new_var == NULL)
		{
			perror("Memory allocation failed");
			return (-1);
		}
		perror("setenv VARIABLE VALUE");
		return (-1); /* Invalid input OR Mem err */
	}
	_strcpy(new_var, name);
	_strcat(new_var, "=");
	_strcat(new_var, value);

	while (*env) /* If 'overwrite' is 1, replace existing variable */
	{
		if (!(_strncmp(name, *env, _strlen(name)))) /* Replace existing variable */
		{
			_strcpy(environ[dx], new_var);
			free(new_var);
			return (0);
		}

		dx++;
		env++;
	}

	environ[dx++] = new_var;
	environ[dx] = '\0';
	return (0);
}
