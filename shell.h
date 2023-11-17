#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>
#include <sys/stat.h>
#include <ctype.h>

extern char **environ;

int _putchar(char c);
void _prompt(void);
void my_printf(const char *command, ...);
void exe_prog(const char *commands);
void user_input(char *format, size_t size);
void arg_line(const char *input, char **av);
char *pathfinder(char *command, const char *path);
void fork_exec(char **args, const char *path);
void tok_input(const char *input, char **args, const char *delim);
int _builtin(char  *arg, char **env);
void arg_linee(char *command);
char *get_loc(char *path, char *file_name);
char *get_path(char *file);
void print_env(char *env[]);
int checkinput(const char *filename);
int is_whitespace(const char *str);

#endif/*MAIN_H*/
