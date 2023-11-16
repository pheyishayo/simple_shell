#include "shell.h"
/**
 * whitespace - checks if there is whitespace character
 * @str: pointer to string
 * Return: 1
 */
int is_whitespace(const char *str)
{
	while (*str != '\0')
	{
		if (!isspace((unsigned char)*str))
		{
			return 0;
		}
	       	str++;
	}
	return 1;
}
