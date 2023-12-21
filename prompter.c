#include "main.h"

/**
	* prompt - char ptr
	* Description: prompts the user to pass some input
	* Return: pointer to buffer containing input
	*/
char *prompt(void)
{
	char *buffer = NULL;
	size_t buffsize = 0;
	int len = 0;

	while (1)
	{
		len = getline(&buffer, &buffsize, stdin);
		if (len == -1 || buffer == NULL)
			break;
		if (buffer[len - 1] == '\n')
			buffer[len - 1] = '\0';
		if (buffer[len - 1] != '\n')
			break;
	}
	if (len == -1)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
