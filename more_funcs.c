#include "shell.h"

/**
 * interactive - returns true if shell is interacctive
 * @info: struct address
 * Return: 1 if interactive mode, 0 other
*/

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if char is a delimeter
 * @ch: char to check
 * @delim: delim string
 * Return: 1 if true, 0 if false
*/

int is_delim(char ch, char *delim)
{
	while (*delim)
		if (*delim++ == ch)
			return (1);
	return (0);
}

/**
 * _isalpha - checks alphabetic chars
 * @ch: input char
 * Return: 1 id ch is alphabet, 0 if not
*/

int _isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch >= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - conv string to int
 * @str: string
 * Return: 0 if no nums in string, other return conv num
*/

int _atoi(char *str)
{
	int i, s = 1;
	int flag = 0;
	int op;
	unsigned int res = 0;

	for (i = 0; str[i] != '\0' && flag != 2; i++)
	{
		if (str[i] == '-')
			s += -1;

		if (str[i] >= '0' && str[i] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (str[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (s == -1)
		op = -res;
	else
		op = res;

	return (op);
}
