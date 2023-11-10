#include "shell.h"
/**
 * main - Entry point
 * Return: 0 on success
 */

int main(void)
{
	char command_line[130];

	while (1)
	{
		_prompt();
		user_input(command_line, sizeof(command_line));
		exe_prog(command_line);
	}
	return (0);
}
