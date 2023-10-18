#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ERROR -1
#define GERRY 1
#define _BFFSZ 1024

typedef char *string;
typedef char **dou_p;
/**
 * struct main - Structure representing a shell built-in command.
 * @key_w: The keyword or command name.
 * @_func: A pointer to the function that handles the command.
 *
 * Return: 0
 */
typedef struct main
{
	string key_w;
	int (*_func)(dou_p dou_argv, size_t line_num, dou_p argv);
} _is;

extern dou_p environ;

char *_strncpy(char *dest, char *src, size_t n);
int _strncmp(char *str1, char *str2, size_t n);
char *_strtok(string str, string _delimiters);
char *_strcat(string dest, string src);
char *_strcpy(string dest, string src);
int _strcmp(string s1, string s2);
int _strchr(string s, char c);
int _print_string(string st);
char *_strdup(string str);
int _strlen(string s);
int _putchar(char c);
int _isdigit(int c);
int _atoi(string s);

int (*_slt(string s))(dou_p dou_argv, size_t line_num, dou_p argv);
int _exit_num(dou_p local_argv, size_t line_num, dou_p argv);
int _unsetenv(dou_p dou_argv, size_t line_num, dou_p argv);
int _setenv(dou_p dou_argv, size_t line_num, dou_p argv);
int _env(dou_p cmmd, size_t line_num, dou_p argv);
int _cd(dou_p cmmd, size_t line_num, dou_p argv);
int _is_prsent(string str);

void _error_MESSAGE(dou_p argv, size_t line_num, dou_p cmmd, string key_w);
void _execmd(dou_p local_argv, dou_p env, dou_p argv, size_t line_num);
int _tokenize_slt_exec(string gtln, dou_p env, dou_p av, size_t l_dx);
size_t _getline(char **getlineptr, size_t *n, int f_d);
dou_p _tokenization(string str, string _delimiters);
void *_realloc(void *ptr, size_t new_size);
void _free(void *_malloc, int is_dou_p);
int _print_num(size_t _n, int _c);
string _get_PATH(string cmmd);
string _getenv(string str);

#endif /* End of Include Guard */
