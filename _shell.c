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
	
	char command_line[150];

	(void)ac;

	while (1)
	{
		_prompt();

		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
		perror("getline");
		exit(EXIT_FAILURE);
		}
		strcpy(command_line, line);

		if (strspn(command_line, " ") < strlen(command_line))
		{
			if (_builtin(command_line, av) == 0)
				arg_line(command_line, av);
			else
				arg_line(command_line, av);
		}
		
	}
	return (0);
}
