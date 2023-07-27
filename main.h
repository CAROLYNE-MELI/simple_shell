#ifndef MAIN_H
#define MAIN_H
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <strings.h>
#include <stddef.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct builtins - struct with builtin commands
 * @argv: arg passed as command
 * @func: correlations function
 * description: this is to handle the builtins
 */
typedef struct builtins
{
	char *argv;
	int (*func)();
} builtins;
char **tokenize(char *userinput);
int string_length(char *str);
int shell_loop(int argc, char **argv);
int execmd(char *asdf, char **argv);
int func_finder(char **argv, char *buffer);
int sh_exit(char **argv, char *buffer);
int _cd(char **argv);
int _env(void);
char *_strcat(char *dest, char *str);
char *hundle_path(char **argv, char **path_tokens);
int _strcmp(char *s1, char *s2);
char *_executable(char *asdf, char **argv);
void _free(char **dpointer);
int _putchar(char c);
char _strchr(char *s, char c);
char *_strdup(char *str);
char **_env_parser(char *name);
char **_get_env(char *env);
extern char **environ;
int _setenv(char **argv);
int _unsetenv(char **argv);
int check_alias(char **argv);
#endif
