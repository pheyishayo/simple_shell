#include "shell.h"

/**
 * pathfinder - Findnthe full path of an executable in the PATH
 * @command: The command to find it
 * @path: The environment PATH Variable
 *
 * Return: full path if found, NULL if otherwises
 */

char *pathfinder(const char *command, const char *path)
{
char *token, *delim = ":";
char *whole_path = NULL;
char *cp_path;
size_t command_len = strlen(command);

cp_path = malloc(strlen(path) + 1);
if (cp_path == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
strcpy(cp_path, path);
token = strtok(cp_path, delim);

while (token != NULL)
{
size_t token_len = strlen(token);
whole_path = malloc(token_len + command_len + 2);
if (whole_path == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
strcpy(whole_path, token);
strcat(whole_path, "/");
strcat(whole_path, command);

if(access(whole_path, X_OK) == 0)
{
free(cp_path);
return (whole_path);
}
free (whole_path);
token = strtok(NULL, delim);
}
free(cp_path);
return (NULL);
}
