#include "shell.h"
/**
 * get_path - find the the path of the input
 * @file: input command
 * Return: 0 on success
 */
char *get_path(char *file)
{
	char *path = getenv("PATH");
	char *find_path;

	if (checkinput(file) && access(file, X_OK) == 0)
		return (strdup(file));
	if (path == NULL)
	{
		perror("not found");
		return (NULL);
	}
	find_path = get_loc(path, file);

	if (find_path == NULL)
	{
		write(2, file, strlen(file));
		write(2, ": command not found\n", 19);
		return (NULL);
	}
	return (find_path);
}
