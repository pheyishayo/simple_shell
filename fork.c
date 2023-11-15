#include "shell.h"
/**
 * fork_exec - fork a chid process and execute command
 * within that procee
 * @args: pointer to array of string
 * @path: pointer to constant character string
 * Return: nothing
 */
void fork_exec(char **args, const char *path)
{
	char *whole_path = pathfinder(args[0], path);

	if (whole_path == NULL)
	{
		perror("whole_path");
		free(args);
		exit(EXIT_FAILURE);
	}
	if (execve(whole_path, args, NULL) == -1)
	{
		perror("execve");
		free(whole_path);
		exit(EXIT_FAILURE);
	}
}

/**
 * tok_input - it tokenize an input string into an array
 * @input: pointer to constant character string
 * @args: pointer to an of character
 * @delim: pointer to constant character string that rep the
 * delimiters used to tokenize th input string
 */
void tok_input(const char *input, char **args, const char *delim)
{
	char *token;
	int j;

	token = strtok((char *)input, delim);
	for (j = 0; token != NULL && (args[j] = strdup(token)); j++)
		token = strtok(NULL, delim);
	args[j] = NULL;
}
