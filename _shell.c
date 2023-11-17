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
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "CPROG$ ", 7);
		nread = getline(&line, &len, stdin);

		if (nread == -1 && feof(stdin))
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (nread == -1)
		{
			perror("getline");
			break;
		}
		else if (is_whitespace(line))
			continue;
		else if (strcmp(line, "exit\n") == 0)
			break;
		arg_linee(line);
	}
	free(line);
	return (0);
}
