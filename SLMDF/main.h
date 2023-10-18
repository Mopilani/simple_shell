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

typedef int make_iso_compilers_happy;

#define ERROR -1
#define BUFSIZE 1024

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

/* _str.c */
char *_strcat(string dest, string src);
int _strcmp(string s1, string s2);
int _strchr(string s, char c);
char *_strcpy(string dest, string src);
char *_strdup(string str);

/* _str1.c */
char *_strncpy(char *dest, char *src, size_t n);
int _strncmp(char *str1, char *str2, size_t n);
char *_strtok(string str, string _delimiters);
int _strlen(string s);
int _print_string(string st);

/* _putchar.c */
int _putchar(char c);

/* _isdigit.c */
int _isdigit(int c);

/* _atoi.c */
int _atoi(string str);

/* slt.c */
int (*_slt(string s))(dou_p dou_argv, size_t line_num, dou_p argv);

/* _exit_num.c */
int _exit_num(dou_p local_argv, size_t line_num, dou_p argv);

/* _env_controle.c */
int _setenv(dou_p dou_argv, size_t line_num, dou_p argv);
int _unsetenv(dou_p dou_argv, size_t line_num, dou_p argv);
int _env(dou_p cmmd, size_t line_num, dou_p argv);

/* _cd.c */
int _cd(dou_p cmmd, size_t line_num, dou_p argv);

/* _cd.c */
int _is_prsent(string str);

/* _error_message.c */
void _error_MESSAGE(dou_p argv, size_t line_num, dou_p cmmd, string key_w);

/* _execmd.c */
void _execmd(dou_p local_argv, dou_p env, dou_p argv, size_t line_num);

/* _tokenizer.c */
int _tokenize_slt_exec(string gtln, dou_p env, dou_p av, size_t l_dx);
dou_p _tokenization(string str, string _delimiters);

/* _getline.c */
size_t _getline(char **getlineptr, size_t *bffsz, int f_d);

/* malloc.c */
void *_realloc(void *ptr, size_t new_size);
void _free(void *_malloc, int is_dou_p);

/* _print_num.c */
int _print_num(size_t _n, int _c);

/* _getters.c */
string _get_PATH(string command);
string _getenv(string str);

#endif
