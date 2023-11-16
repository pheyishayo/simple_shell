#include "shell.h"
/**
 * get_path - find the the path of the input
 * @file: input command
 * Return: 0 on success
 */
char *get_path(char *file)
{
	char *path = getenv("PATH");
	char *find_path, *result;

	if (checkinput(file) && access(file, X_OK) == 0)
	{
		result = strdup(file);
		if (result == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}
		return (result);
	}
	if (!path)
	{
		fprintf(stderr, "PATH variable not set\n");
		return (NULL);
	}
	find_path = get_loc(path, file);

	if (find_path == NULL)
	{
		errno = ENOENT;
		return (NULL);
	}
	return (find_path);
}
