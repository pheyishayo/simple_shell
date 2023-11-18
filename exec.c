#include "shell.h"
/**
 * arg_linee - execute the input command
 * @command: the input
 * Return: no return
 */
void arg_linee(char *command)
{
	pid_t child_pid;
	int status, i, j;
	char *token, *path;
	char **array;

	token = strtok(command, "\n ");
	array = malloc(sizeof(char *) * 1024);
	i = 0;
	while (token)
	{
		array[i] = strdup(token);
		token = strtok(NULL, "\n ");
		i++;
	}
	array[i] = NULL;
	path = get_path(array[0]);

	if (path == NULL)
		perror("./hsh$");
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("failed to execute");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (execve(path, array, NULL) == -1)
		{
			/*perror("execve");*/
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
	for (j = 0; j < i; j++)
		free(array[j]);
	free(array);
	free(path);
}
