#include "shell.h"
/**
 * get_loc - get executable path
 * @path: full path
 * @file_name: The executable file
 * Return: full path
 */
char *get_loc(char *path, char *file_name)
{
	char *path_copy, *token, *result = NULL;
	struct stat file_path;
	char *path_buffer = NULL;

	path_copy = strdup(path);
	token = strtok(path_copy, ":");

	while (token)
	{
		if (path_buffer)
		{
			free(path_buffer);
			path_buffer = NULL;
		}
		path_buffer = malloc(strlen(token) + strlen(file_name) + 2);

		if (!path_buffer)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}
		strcpy(path_buffer, token);
		strcat(path_buffer, "/");
		strcat(path_buffer, file_name);
		strcat(path_buffer, "\0");

		if (stat(path_buffer, &file_path) == 0 && access(path_buffer, X_OK) == 0)
		{
			/*free(path_copy);*/
			result = path_buffer;
			return (result);
		}

		token = strtok(NULL, ":");
	}
	free(path_copy);
	if (!result && path_buffer)
		free(path_buffer);
	return (NULL);
}
