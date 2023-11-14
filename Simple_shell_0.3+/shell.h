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

void _prompt(void);
void my_printf(const char *command, ...);
void exe_prog(const char *commands);
void user_input(char *format, size_t size);
void arg_line(const char *input, char **av);
char *pathfinder(char *command, const char *path);
void fork_exec(char **args, const char *path);
void tok_input(const char *input, char **args, const char *delim);
int _builtin(char  *arg);

#endif/*MAIN_H*/
