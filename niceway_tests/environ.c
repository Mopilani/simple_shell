#include "shell.h"

/**
 * _menv - print current environment
 * @info: Structure containing potential arguments.
 * Return: 0
 */
int _menv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _get_env_val - gets the value of an environ variable
 * @info: Structure containing potential arguments.
 * @name: env name
 *
 * Return: the value
 */
char *_get_env_val(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *ptr;

	while (node)
	{
		ptr = starts_with(node->str, name);
		if (ptr && *ptr)
			return (ptr);
		node = node->next;
	}
	return (NULL);
}

/**
 * _new_setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments.
 *  Return: 0
 */
int _new_setenv(info_t *info)
{
	if (info->argc != 3)
	{
		_puts("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _rm_unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments.
 *  Return:  0
 */
int _rm_unsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
		_puts("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_lst - populates env linked list
 * @info: Structure containing potential arguments.
 * Return: 0
 */
int populate_env_lst(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}
