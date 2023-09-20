#include "shell.h"
/**
 * is_cmd - determines if the file is exectuable
 * @info: struct para
 * @path: path to file
 * Return: 1 if true 0 otherwise
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - suplicates the characters
 * @pathstr: para
 * @start: para
 * @stop: para
 * Return: pointer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}
/**
 * find_path - finds the path of the cmd
 * @info: para
 * @pathstr: para
 * @cmd: para
 * Return: the path
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr, i);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr = i;
		}
		i++;
	}
	return (NULL);
}
