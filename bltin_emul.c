#include "shell.h"
/**
 *  _myexit - exits from the shell
 *  @info: struct para
 *  Return: exit with status
 */
int _myexit(info_t *info)
{
	int exitchck;

	if (info->argv[1])
	{
		exitchck = _erratoi(info->argv[1]);
		if (exitchck == -1)
		{
			info->stat = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 *  _mycd - changes directory
 *  @info: struct para
 *  Return: exit with status
 */
int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int cd_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			cd_ret = chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			cd_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		cd_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		cd_ret = chdir(info->argv[1]);
	if (cd_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 *  _myhelp - exits from the shell
 *  @info: struct para
 *  Return: exit with status
 */
int _myhelp(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
