#include "shell.h"

/**
 * _strcpy - copies string
 * @dest: destination
 * @src: source
 * Return: ptr to dest
*/

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strdup - duplicates string
 * @str: string
 * Return: ptr to dup string
*/

char *_strdup(const char *str)
{
	int len = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (NULL);
	for (len++; len--;)
		dup[len] = *--str;
	return (dup);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes character c to stdout
 * @c: character to print
 * Return: 1 on success, -1 on error, and errno is set
*/

int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SZ];

	if (c == BUF_FLSH || i >= WRITE_BUF_SZ)
	{
		write(1, buf, i);
	}
	if (c != BUF_FLSH)
		buf[i++] = c;
	return (1);
}
