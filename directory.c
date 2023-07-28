#include "header.h"
/**
 * hundle_path - hundles the  PATH of commands
 * @argv: array of strings
 * @path_tokens: array of strings containing our tokenized PATH
 * Return: thre path of commands
**/
char *hundle_path(char **argv, char **path_tokens)
{
	struct dirent *dir_store;
	DIR *dr = NULL;
	int m;
	char *asdf = NULL;
	char *store = NULL;

	if (argv[0][0] == '/')
		return (argv[0]);
	for (m = 0; path_tokens[m] != '\0'; m++)
	{
		dr = opendir(path_tokens[m]);
		while ((dir_store = readdir(dr)) != NULL)
		{
			if (_strcmp(argv[0], dir_store->d_name) == 0)
			{
				asdf = path_tokens[m];
				store = _executable(asdf, argv);
				closedir(dr);
				return (store);
			}
		}
	closedir(dr);
	}
	return (NULL);
}

/**
 * _executable - makes an executable
 * @asdf: stores the path of the correct directory
 * @argv: argv[0] is concatenated to asdf
 * Return: modified asdf
**/
char *_executable(char *asdf, char **argv)
{
	char *slash = NULL;
	char *newcmd = NULL;

	slash = _strcat(asdf, "/");
	newcmd = _strcat(slash, argv[0]);
	free(slash);
	return (newcmd);
}
/**
*_strcat - concatinates tow strings
*@dest: string to copy to
*@str: string to be copied
*Return: then  coppied strin dest
**/
char *_strcat(char *dest, char *str)
{
	int a, p, x;
	char *newcmd = NULL;

	for (p = 0; dest[p] != '\0'; p++)
	{}
	for (a = 0; str[a] != '\0'; a++)
	{}
	newcmd = malloc(sizeof(char) * (a + p + 1));
	for (x = 0; x < p; x++)
	{
		newcmd[x] = dest[x];
	}
	for (x = 0; x < a; x++)
	{
		newcmd[x + p] = str[x];
	}
	newcmd[x + p] = '\0';
	return (newcmd);
}
