#include "main.h"

/**
 * is_cmd - determines if file is an executable command
 * @info:  info struct
 * @path: path to the file
 *
 * Return: 1 if true, 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat s;

	(void)info;
	if (!path || stat(path, &s))
		return (0);

	if (s.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - duplicate characters
 * @pathstr: the path string
 * @start: start index
 * @stp: stop index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stp)
{
	static char buffer[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stp; i++)
		if (pathstr[i] != ':')
			buffer[k++] = pathstr[i];
	buffer[k] = 0;
	return (buffer);
}

/**
 * find_path - finds this cmd in the PATH string
 * @info: the info struct
 * @pathstr: the PATH string
 * @cmd: cmd to find
 *
 * Return: full path of cmd if found or NULL
 */
char *find_path(info_t *info, char *path_str, char *cmd)
{
	int i = 0, curr_pos = 0;
	char *path;

	if (!path_str)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!path_str[i] || path_str[i] == ':')
		{
			path = dup_chars(path_str, curr_pos, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!path_str[i])
				break;
			curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
