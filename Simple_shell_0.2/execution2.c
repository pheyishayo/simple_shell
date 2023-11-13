#include "shell.h"
/**
 * arg_line - This function takes arguments
 * @input: pointer to constant string of character
 * @av: pointer to array of characters
 */
void arg_line(const char *input, char **av)
{
	const int max = 1024;
	pid_t child_pid;
	char *token, *delim = "\n ";
	int i, j, status;
	char **args = malloc(sizeof(char *) * max);

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		free(args);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		for (i = 0; i < max; i++)
			args[i] = NULL;
		token = strtok((char *)input, delim);
		for (j = 0; token != NULL && (args[j] = token); j++)
			token = strtok(NULL, delim);
		if (args[0] != NULL)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		free(args);
		exit(EXIT_SUCCESS);
	}
	else
		waitpid(child_pid, &status, 0);
}
