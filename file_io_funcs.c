#include "shell.h"
/**
 * get_hist_file - gets the history
 * @info: struct para
 * Return: alloc string that contains the history file
*/

char *get_hist_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");

	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}
/**
 * write_hist - create hist file
 * @info: struct para
 * Return: 1 if valid, 0 if not
*/
int write_hist(info_t *info)
{
	ssize_t fd;
	char *f_name = get_hist_file(info);
	list_t *node = NULL;

	if (!f_name)
		return (-1);

	fd = open(f_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(f_name);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLSH, fd);
	close(fd);
	return (1);
}
/**
 * read_hist - reads the history from the file
 * @info: struct para
 * Return: no of hist on success otherwise 0
*/
int read_hist(info_t *info)
{
	int i, lst = 0, l_count = 0;
	ssize_t fd, rd_len, f_size = 0;
	struct stat st;
	char *buf = NULL, *f_name = get_hist_file(info);

	if (!f_name)
		return (0);

	fd = open(f_name, O_RDONLY);
	free(f_name);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		f_size = st.st_size;
	if (f_size < 2)
		return (0);
	buf = malloc(sizeof(char) * (f_size + 1));
	if (!buf)
		return (0);
	rd_len = read(fd, buf, f_size);
	buf[f_size] = 0;
	if (rd_len <= 0)
		return (free(buf), 0);
	close(fd);
	for (i = 0; i < f_size; i++)
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			build_hist_list(info, buf + lst, l_count++);
			lst = i + 1;
		}
	if (lst != i)
		build_hist_list(info, buf + lst, l_count++);

	free(buf);
	info->hist_cnt = l_count;
	while (info->hist_cnt-- >= HIST_MAX)
		delete_node_at_indx(&(info->history), 0);
	renum_hist(info);
	return (info->hist_cnt);

}

/**
 * build_hist_list - add entry to history linked list
 * @info: struct para
 * @buf: para
 * @linecount: para
 * Return: 0
*/

int build_hist_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renum_hist - renumbers the history linked list
 * @info: struct para
 * Return: int
 */

int renum_hist(info_t *info)
{
	list_t *node = info->history;
	int i = 0;

	while (node)
	{
		node->num = i++;
		node = node->next;
	}
	return (info->hist_cnt = i);
}
