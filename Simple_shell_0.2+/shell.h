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

void _prompt(void);
void my_printf(const char *command, ...);
void exe_prog(const char *commands);
void user_input(char *format, size_t size);
void arg_line(const char *input, char **av);
char *pathfinder(const char *command, const char *path);

#endif/*MAIN_H*/
