#include "shell.h"
/**
 * checkinput - check if the function start
 * with foward slash
 * @filename: file to be checked.
 * Return: 0 if yes and 1 if no
 */
int checkinput(const char *filename)
{
	if (filename != NULL || filename[0] == '/')
		return (1);
	return (0);
}
