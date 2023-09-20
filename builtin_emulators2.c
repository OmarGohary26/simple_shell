#include "shell.h"
/**
 *  _myhist - displays history
 *  @info: struct para
 *  Return: 0
 */
int _myhist(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 *  unset_alias - unsets alias
 *  @info: struct para
 *  @str: para
 *  Return: 0 if not 1
 */
int unset_alias(info_t *info, char *str)
{
	char c, *p;
	int r;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	r = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (r);
}
/**
 * set_alias - sets alias
 * @info: struct para
 * @str: para
 * Return: Alway 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 * print_alias - prints alias string
 * @node: para
 * Return: Alway 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL;
	char *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		{
			_putchar(*a);
		}
		_putchar('\');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
