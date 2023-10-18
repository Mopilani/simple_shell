#include "main.h"

/**
 * _getenv - Loops through all env variables to locate the key_w in 'str'.
 * @str: The key word to be searched in environmental varables.
 * Return: The address to the value after the '=' sign. "OLDPWD="
 */
string _getenv(string str)
{
	size_t lx = _strlen(str);
	dou_p _env_cp = environ;

	for (; *_env_cp; ++_env_cp)
	{
		if (!(_strncmp(*_env_cp, str, lx)) && (*_env_cp)[lx] == '=')
			return (&(*_env_cp)[lx + 1]);

	}
	return (NULL);
}
