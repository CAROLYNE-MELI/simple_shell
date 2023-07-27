#include "main.h"
/**
 * sh_exit - exits the shell
 * @argv: array of arguments
 * @buffer: buffer to be exited
 * Return: 0
 */
int sh_exit(char **argv, char *buffer)
{
	free(argv);
	free(buffer);
	exit(0);
}

/**
 * _env - prints the details of environment variable
 * Return: 0
 */
int _env(void)
{
	int m;
	int h;

	char *string = NULL;

	for (m = 0; environ[m] != NULL; m++)
	{
		for (h = 0; environ[m][h] != '\0'; h++)
		{
			string = (&(environ[m][h]));
			write(STDOUT_FILENO, string, string_length(string));
			break;
		}
		_putchar('\n');
	}
	return (0);
}
/**
* _setenv - sets the env of enviroment
* @argv: array of arguments
* Return: 0
*/
int _setenv(char **argv)
{
	argv = argv;
	return (0);
}
/**
* _unsetenv - unsets the env of enviroment
* @argv: array of arguments
* Return: 0
*/
int _unsetenv(char **argv)
{
	argv = argv;
	return (0);
}

/**
 * _cd - changes current directory
 * @argv: array of arguments
 * Return: 0
**/
int _cd(char **argv)
{
	argv = argv;
	return (0);
}
