#include "shell.h"

/**
 * list_len - gets length of linked list
 * @hd: head ptr
 *
 * Return: list sz
 */

size_t list_len(const list_t *hd)
{
	size_t i = 0;

	while (hd)
	{
		hd = hd->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @hd: head ptr
 *
 * Return: array of strings
 */
char **list_to_strings(list_t *hd)
{
	list_t *node = hd;
	size_t i = list_len(hd), j;
	char **strings;
	char *str;

	if (!hd || !i)
		return (NULL);
	strings = malloc(sizeof(char *) * (i + 1));
	if (!strings)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strings[j]);
			free(strings);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strings[i] = str;
	}
	strings[i] = NULL;
	return (strings);
}

/**
 * print_list - prints all elements of a list_t ll
 * @hd: head ptr
 * Return: list sz
 */
size_t print_list(const list_t *hd)
{
	size_t i = 0;

	while (hd)
	{
		_puts(conv_num(hd->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hd->str ? hd->str : "(nil)");
		_puts("\n");
		hd = hd->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns node that its string starts with prefix
 * @hd: head ptr
 * @pref: string to match
 * @ch: the next character after prefix
 * Return: match node or null
 */
list_t *node_starts_with(list_t *hd, char *pref, char ch)
{
	char *ptr = NULL;

	while (hd)
	{
		ptr = starts_with(hd->str, pref);
		if (ptr && ((ch == -1) || (*ptr == ch)))
			return (hd);
		hd = hd->next;
	}
	return (NULL);
}

/**
 * get_node_indx - gets node indx
 * @hd: head ptr
 * @node: node ptr
 * Return: index of node or -1
 */
ssize_t get_node_indx(list_t *hd, list_t *node)
{
	size_t i = 0;

	while (hd)
	{
		if (hd == node)
			return (i);
		hd = hd->next;
		i++;
	}
	return (-1);
}
