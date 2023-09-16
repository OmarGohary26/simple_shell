#include "shell.h"

/**
 * **strtow - splits string into words and ignoring repeat delim
 * @str: string
 * @delim: delim string
 * Return: ptr to array of strings or NULL
*/

char **strtow(char *str, char *delim)
{
	int i, j, k, l, wordctr = 0;
	char **p;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!delim)
		delim = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], delim) && (is_delim(str[i + 1], delim) || !str[i + 1]))
			wordctr++;
	if (wordctr == 0)
		return (NULL);
	p = malloc((1 + wordctr) * sizeof(char *));
	if (!p)
		return (NULL);
	for (i = 0; j = 0; j < wordctr; j++)
	{
		while (is_delim(str[i], delim))
			i++;
		k = 0;
		while (!is_delim(str[i + k], delim) && str[i + k])
			k++;
		p[j] = malloc((k + 1) * sizeof(char));
		if (!p[j])
		{
			for (k = 0; k < j; k++)
				free(p[k]);
			free(p);
			return (NULL);
		}
		for (l = 0; l < k; l++)
			p[j][l] = str[i++];
		p[j][l] = 0;
	}
	p[j] = NULL;
	return (p);
}

/**
 * **strtow2 - splits string into words
 * @str: input string
 * @delim: delimeter
 * Return: ptr to array of strings or NULL
*/

char **strtow2(char *str, char delim)
{
	int i, j, k, l, wordctr = 0;
	char **p;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != delim && str[i + 1] == delim) ||
				(str[i] != delim && !str[i + 1]) || str[i + 1] == delim)
			wordctr++;
	if (wordctr)
		return (NULL);
	p = malloc((1 + wordctr) * sizeof(char *));
	if (!p)
		return (NULL);
	for (i = 0; j = 0; j < wordctr; j++)
	{
		while (str[i] == delim && str[i] != delim)
			i++;
		k = 0;
		while (str[i + k] != delim && str[i + k] && str[i + k] != delim)
			k++;
		p[j] = malloc((k + 1) * sizeof(char));
		if (!p[j])
		{
			for (k = 0; k < j; k++)
				free(p[k]);
			free(p);
			return (NULL);
		}
		for (l = 0; l < k; l++)
			p[j][l] = str[i++];
		p[j][l] = 0;
	}
	p[j] = NULL;
	return (p);
}


