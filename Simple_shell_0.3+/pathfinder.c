#include "shell.h"
/**
 * pathfinder - find the full path of executable command
 * @command: pointer to executable input to be searched for
 * @path: pointer to a const character string
 * Return: full path if found, othewise NULL
 */
char *pathfinder(char *command,const char *path)
{
	const char *delim = ":";
	char *whole_path = NULL;
	char *cp_path, *token;
	size_t command_len = strlen(command), path_len;
	struct stat buff;

	cp_path = strdup(path);
	if (cp_path == NULL)
	{
		perror("strdup");
		exit(EXIT_FAILURE);
	}
	token = strtok(cp_path, delim);

	while (token != NULL)
	{
		path_len = strlen(path);
		whole_path = malloc(path_len + command_len + 2);
		if (whole_path == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		strcpy(whole_path, token);
		strcat(whole_path, "/");
		strcat(whole_path, command);
		if (stat(whole_path, &buff) == 0)
		{
			free(cp_path);
			return (whole_path);
		}
		free(whole_path);
		token = strtok(NULL, delim);
	}
	free(cp_path);
	if (stat(command, &buff) == 0)
		return (command);
	return (NULL);
}
