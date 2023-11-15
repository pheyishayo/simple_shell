#include "shell.h"

/**
 * print_env - print content of env variable area
 * @env: array of strings that represent
 * enviroment variable
 * Return: nothing
 */

void print_env(char *env[])
{
	int j, i = 0;

	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
		{
			_putchar(env[i][j]);
			j++;
		}
		_putchar('\n');
		i++;
	}
}
/**
 * _builtin - it handles builtin command
 * @arg: pointer to character array
 * @env: apointer to array of string and
 * represent the enviroment varible
 * Return: 0 0n success
 */
int _builtin(char  *arg, char **env)
{
	if (strcmp(arg, "exit") == 0)
	{
		my_printf("exit\n");
		exit(0);
	}
	else if (strcmp(arg, "env") == 0)
	{
		print_env(env);
	}
	return (0);
}
