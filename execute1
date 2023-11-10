#include "shell.h"
/**
 * exe_prog - this function execute a command line
 * line without taking arguements
 * @input: pointer to array of stings that store
 * inputs from users.
 * Return: -1 if fails
 */

void exe_prog(const char *input)
{
	char *argv[] = {"/bin/ls", NULL};
	pid_t childpid = fork();
	int status;
	int arg;

	if (childpid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (childpid == 0)
	{
		if (strcmp(input, argv[0]) != 0)
		{
			errno = ENOENT;
			perror("execve");
			exit(EXIT_FAILURE);
		}

		arg = execve(argv[0], argv, NULL);
		perror("execve");
		if (arg == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
