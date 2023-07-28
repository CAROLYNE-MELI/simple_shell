#include "header.h"
/**
 * func_finder - hundles the builtin functions
 * @argv: array of arguments
 * @buffer: buffer
 * Return: 0
 */
int func_finder(char **argv, char *buffer)
{
	int m;

	builtins arr[] = {
		{"env", _env},
		{"exit", sh_exit},
		{"cd", _cd},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"alias", check_alias},
		{'\0', NULL}
	};

	if (argv != NULL)
	{
		if (_strcmp(argv[0], "exit") == 0)
		{
			sh_exit(argv, buffer);
			return (1);
		}
		for (m = 0; arr[m].func; m++)
		{
			if (_strcmp(argv[0], arr[m].argv) == 0)
			{
				arr[m].func();
				return (1);
			}
		}
	}
	return (0);
}
/**
 * check_alias - checks for the number ofalias
 * @argv: array of arguments
 * Return: 0
**/
int check_alias(char **argv)
{
	argv = argv;
	return (0);
}
