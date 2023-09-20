#include "shell.h"

/**
 *_eputs - prints string
 * @s: the string
 * Return: none
 */
void _eputs(char *s)
{
	int itr = 0;

	if (!s)
		return;
	while (s[itr] != '\0')
	{
		_eputchar(s[itr]);
		itr++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @ch: char to print
 * Return: 1 success, -1 if error and errno is set
 */
int _eputchar(char ch)
{
	static int i;
	static char buf[WRITE_BUF_SZ];

	if (c == BUF_FLSH || i >= WRITE_BUF_SZ)
	{
		write(2, buf, i);
		i = 0;
	}
	if (ch != BUF_FLSH)
		buf[i++] = ch;
	return (1);
}

/**
 * _putfd - writes the character ch to given fd
 * @ch: char to print
 * @fd: the filedescriptor to write to
 * Return: 1 when success, -1 returned, errno is set
 */

int _putfd(char ch, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SZ];

	if (ch == BUF_FLSH || i >= WRITE_BUF_SZ)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (ch != BUF_FLSH)
		buf[i++] = ch;
	return (1);
}

/**
 *_putsfd - prints string
 * @s: the string
 * @fd: the filedescriptor to write to
 * Return: the number of chars put
 */
int _putsfd(char *s, int fd)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s)
	{
		i += _putfd(*s++, fd);
	}
	return (i);
}
