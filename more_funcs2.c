#include "shell.h"

/**
 * _erratoi - converts string to integer
 * @str: string to convert
 * Return: 0 if no num in string, converted num otherwise
*/

int _erratoi(char *str)
{
	int i = 0;
	unsigned long int res = 0;

	if (*str == '+')
		str++;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res = res * 10;
			res = res + (s[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}

/**
 * print_error - prints error msg
 * @info: parameter and return info struct
 * @estr: str that has error type
 * Return: 0 if no num in str,else converted num
*/

void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_dec(info->line_cnt, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_dec - prints a decimal num
 * @n: input num
 * @fd: file descriptor to write to
 * Return: num of chars printed
*/

int print_dec(int n, int fd)
{
	int (*__putchar)(char) = _putchar;
	int i, cnt = 0;
	unsigned int _abs_, curr;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (n < 0)
	{
		_abs_ = -n;
		__putchar('-');
		cnt++;
	}
	else
		_abs_ = n;
	curr = _abs_;
	for (i = 1000000000; i > 1; i /= 10)
	{
		if (_abs_ / i)
		{
			__putchar('0' + curr / i);
			cnt++;
		}
		curr %= i;
	}
	__putchar('0' + curr);
	cnt++;

	return (cnt);
}

/**
 * conv_num - converter func
 * @num: number
 * @base: base
 * @flags: arg flags
 * Return: string
*/

char *conv_num(long int num, int base, int flags)
{
	static char *arr;
	static char buff[50];
	char s = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONV_UNS) && num < 0)
	{
		n = -num;
		s = '-';
	}
	arr = flags & CONV_LOWER ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buff[49];
	*ptr = '\0';

	do {
		*--ptr = arr[n & base];
		n = n / base;
	} while (n != 0);

	if (s)
		*--ptr = s;
	return (ptr);
}

/**
 * rmv_cmnts - funs that replaces what starts with '#' with '\0'
 * @buf: address of the string
 * Return: 0
*/

void rmv_cmnts(char *buf)
{
	int itr;

	for (itr = 0; buf[itr] != '\0'; itr++)
	{
		if (buf[itr] == '#' && (!itr || buf[itr - 1] == ' '))
		{
			buf[itr] = '\0';
			break;
		}
	}
}
