#include "main.h"

/**
 * get_PATH - This function gets all PATHs
 *                          and determine the path for the command.
 * @cmmd: The command from stdin who's path is to be found.
 * Return: A pointer to valid PAth or NULL if it doesn't exist.
 */
string _get_PATH(string cmmd)
{
	int dir_length, cmmd_length;
	string path = NULL, _token = NULL, _addr = NULL, _cmmd = NULL;
	char path_cp[_BFFSZ], file_path[_BFFSZ];
	struct stat bffr;

	path = getenv("PATH");

	if (path)
	{
		_strcpy(path_cp, path);
		cmmd_length = _strlen(cmmd);

		_token = _strtok(path_cp, ":");
		while (_token != NULL)
		{
			dir_length = _strlen(_token);

			_strcpy(file_path, _token);
			_strcat(file_path, "/");
			_strcat(file_path, cmmd);
			_strcat(file_path, "\0");

			if (!(stat(file_path, &bffr)))
			{
				_addr = malloc(cmmd_length + dir_length + 2);
				_strcpy(_addr, file_path);
				return (_addr);
			}

			_token = _strtok(NULL, ":");
		}

		if (!(stat(cmmd, &bffr))) /* /bin/ls */
		{
			_cmmd = malloc(cmmd_length + 1);
			_strcpy(_cmmd, cmmd);
			return (_cmmd);
		}
	}
	return (NULL);
}


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
