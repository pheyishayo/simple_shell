#include "shell.h"
/**
 * my_printf - function that print to standard output
 * @commands: pointer to array of string
 * Return: nothing
 */
void my_printf(const char *commands, ...)
{
	write(STDOUT_FILENO, commands, strlen(commands));
}
