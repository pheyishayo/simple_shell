#include "shell.h"

/**
 * arg_line - This function process a command line arguement
 * @input: ponter to constant character
 * @av: pointer to a pointer to a character
 * Return: no return type
*/ 
void arg_line(const char *input, char **av __attribute__((unused)))
{
	const int max = 1024;
	int i, status;
	char **args = malloc(sizeof(char *) * max);
	pid_t child_pid;
	char *path = getenv("PATH");

	if (args == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < max; i++)
		args[i] = NULL;
	tok_input(input, args, "\n ");
	if (args[0] == NULL)
	{
		my_printf("Error: no input\n");
		free(args);
		exit(EXIT_FAILURE);
	}
	_builtin(args[0], environ);
	child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free(args);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
		fork_exec(args, path);
	else
		waitpid(child_pid, &status, 0);
	for (i = 0; i < max && args[i] != NULL; i++)
		free(args[i]);
	free(args);
}
