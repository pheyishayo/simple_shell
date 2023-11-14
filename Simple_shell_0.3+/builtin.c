#include "shell.h"

/**
 * _builtin - it handles builtin command
 * @arg: pointer to character array
 * Return: 0 0n success
 */
int _builtin(char  *arg)
{
	if (strcmp(arg, "exit") == 0)
	{
		my_printf("exit\n");
		exit(0);
	}
	return (0);
}
