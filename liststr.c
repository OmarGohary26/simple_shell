#include "shell.h"

/**
 * add_node - adds node to the head of the list
 * @head: address of head pointer
 * @str: data of node
 * @num: node index
 * Return: list size
*/

list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *nw_hd;

	if (!head)
		return (NULL);
	nw_hd = malloc(sizeof(list_t));
	if (!nw_hd)
		return (NULL);
	_memset((void *)nw_hd, 0, sizeof(list_t));
	nw_hd->num = num;
	if (str)
	{
		nw_hd->str = _strdup(str);
		if (!nw_hd->str)
		{
			free(nw_hd);
			return (NULL);
		}
	}
	nw_hd->next = *head;
	*head = nw_hd;
	return (nw_hd);
}

/**
 * add_node_end - adds node to tail
 * @head: address of head ptr
 * @str: data of node
 * @num: node index
 * Return: list sz
*/

list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - prints str of a list_t
 * @hd: head ptr
 * Return: list sz
*/

size_t print_list_str(const list_t *hd)
{
	size_t i = 0;

	while (hd)
	{
		_puts(hd->str ? hd->str : "(nil)");
		_puts("\n");
		hd = hd->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_indx - deletes node at an index
 * @hd: address to head ptr
 * @idx: index of node
 * Return: 1 success, 0 for fail
*/

int delete_node_at_indx(list_t **hd, unsigned int idx)
{
	list_t *node, *prev_n;
	unsigned int i = 0;

	if (!hd || !*hd)
		return (0);

	if (!idx)
	{
		node = *hd;
		*hd = (*hd)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *hd;
	while (node)
	{
		if (i == idx)
		{
			prev_n->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_n = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @hd: head ptr
 * Return: nothing
*/

void free_list(list_t **hd)
{
	list_t *node, *next_n, *head;

	if (!hd || !*hd)
		return;
	head = *hd;
	node = head;
	while (node)
	{
		next_n = node->next;
		free(node->str);
		free(node);
		node = next_n;
	}
	*hd = NULL;
}
