#include "main.h"
/**
 * _strcmp - compares strings
 * @s1: input string 1
 * @s2: input string 2
 * Return: s1[m] - s2[h] on failure or 0 on success
**/
int _strcmp(char *s1, char *s2)
{
	int m = 0, h = 0;

	for ( s1[m] != '\0' || s2[h] != '\0'; m++, h++;)
	{
		if (s1[m] != s2[h])
		{
			return (s1[m] - s2[h]);
		}
	}
return (0);
}

/**
 * string_length - finds the length of string
 * @s:input string
 * Return: the length of string
**/
int string_length(char *str)
{
	int m;

	for (m = 0; str[m] != '\0'; m++)
	{}
		return (m);
}

/**
 * _strdup - hellps to duplicates a string
 * @str: the string to be duplicate
 * Return: NULL on failure/pointer to string dublicate
**/
char *_strdup(char *str)
{
	char *dupstr = NULL;
	int s;
	int len = 0;

	if (str == NULL)
		return (NULL);
	for (len = 0; str[len] != '\0'; len++);
	dupstr = malloc((len + 1) * sizeof(char));
	if (dupstr == NULL)
		return (NULL);
	for (s = 0; s <= len; s++)
		dupstr[s] = str[s];
	return (dupstr);
}
/**
 * _free - frees double pointers
 * @dpointer: double pointer
 * Return: void
**/
void _free(char **dpointer)
{
	int m = 0;

	while (dpointer[m])
	{
		free(dpointer[m]);
		m++;
	}
	free(dpointer);
}
