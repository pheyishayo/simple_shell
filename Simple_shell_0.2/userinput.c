#include "shell.h"

/**
 * user_input - This function reads input from the user
 * @input: pointer to character array
 * @size: rep the size of buffer
 * Return: nothing
 */

void user_input(char *input, size_t size)
{
	if (fgets(input, size, stdin) == NULL)
	{
		if (feof(stdin))
		{
			my_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			my_printf("Input Error.\n");
			exit(EXIT_FAILURE);
		}
	}
	input[strcspn(input, "\n")] = '\0';
}
