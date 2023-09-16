#include "shell.h"

/**
 * *_strncpy - copies string
 * @dest: destination string
 * @src: source string
 * @n: number of characters to copy
 * Return: the concat string
*/

char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *st = dest;

	i = 0;
	while (src[i] != '\0'  && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (st);
}

/**
 * *_strncat - concats 2 strings
 * @dest: first string
 * @src: second string
 * @n: max num of bytes to be used
 * Return: concat string
*/

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *st = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (st);
}

/**
 * *_strchr - gets a character in a string
 * @s: string to parse
 * @c: character to search for
 * Return: ptr to memory area s
*/

char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
