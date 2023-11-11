#include "shell.h"
/**
 * arg_line - This function takes arguments
 * @input: reps a pointer to constant string of character
 * @av: This is pointer to an array arguments to be
 * passed to new process
 * Return: -1 if fail
 */

void arg_line(const char *input, char **av)
{
	pid_t child_pid = fork();
	int status, count = 0;
	char *token;

	char *env[] = {NULL};

	av = malloc(sizeof(char *) * 1024);

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		av[0] = "/bin/ls";
		av[1] = NULL;
		token = strtok((char *)input, " ");

		while (token != NULL)
		{
			av[count] = token;
			token = strtok(NULL, " ");
			count++;
		}
		av[count] = NULL;
		free(av);
		if (count > 0)
		{
			if (execve(av[0], av, env) == -1)
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
		wait(&status);
}
