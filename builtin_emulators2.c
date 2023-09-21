#include "shell.h"
/**
 *  _myhist - displays history
 *  @info: struct para
 *  Return: 0
 */
int _myhist(info_t *info)
{
	print_list(info->hist);
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
	r = delete_node_at_indx(&(info->alias),
			get_node_indx(info->alias, node_starts_with(info->alias, str, -1)));
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
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		p = _strchr(info->argv[i], '=');
		if (p)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
