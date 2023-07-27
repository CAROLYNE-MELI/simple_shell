#include "main.h"
/**
 * hundle_path - hundles the  PATH of commands
 * @argv: array of strings
 * @path_tokens: array of strings containing our tokenized PATH
 * Return: thre path of commands
**/
char *hundle_path(char **argv, char **path_tokens)
{
	struct dirent *dir_keep;
	DIR *dr = NULL;
	int m;
	char *asdf = NULL;
	char *keep = NULL;

	if (argv[0][0] == '/')
		return (argv[0]);
	for (m = 0; path_tokens[m] != '\0'; m++)
	{
		dr = opendir(path_tokens[m]);
		while ((dir_keep = readdir(dr)) != NULL)
		{
			if (_strcmp(argv[0], dir_keep->d_name) == 0)
			{
				asdf = path_tokens[m];
				keep = _executable(asdf, argv);
				closedir(dr);
				return (keep);
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
	int a, b, c;
	char *newcmd = NULL;

	for (b = 0; dest[b] != '\0'; b++)
	{}
	for (a = 0; str[a] != '\0'; a++)
	{}
	newcmd = malloc(sizeof(char) * (a + b + 1));
	for (c = 0; c < b; c++)
	{
		newcmd[c] = dest[c];
	}
	for (c = 0; c < a; c++)
	{
		newcmd[c + b] = str[c];
	}
	newcmd[c + b] = '\0';
	return (newcmd);
}
