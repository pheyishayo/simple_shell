#include "shell.h"
/**
 * main - Entry point
 * @ac: this count the number of arguments
 * @av: this store number of arguments passed to
 * the command line. it a pointer to array of
 * string.
 * Return: 0 on success
 */

int main(int ac, char **av)
{

	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	(void)av;
	(void)ac;

	while (1)
	{
		write(STDOUT_FILENO, "CPROG$ ", 7);
		nread = getline(&line, &len, stdin);

		if (nread == -1)
		{
			perror("getline");
			exit(1);
		}
		arg_linee(line);
	}
	free(line);
	return (0);
}
