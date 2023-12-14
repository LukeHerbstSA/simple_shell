#include "main.h"

/**
	* prompt - char ptr
	* Description: prompts the user to pass some input
	* Return: pointer to buffer containing input
	*/
char *prompt(void)
{
	char *buffer = NULL;
	char *token = NULL;
	size_t buffsize = 0;
	int len = 0;

	token = malloc(100);
	if (token == NULL)
	{
		perror("Issue with allocating memory\n");
		return (NULL);
	}
	if (isatty(0))
		printf("$ ");
	while (1)
	{
		len = getline(&token, &buffsize, stdin);
		if (len == -1)
			break;
		if (token[len - 1] == '\n')
			token[len - 1] = '\0';
		buffer = malloc(_len(token) + 1);
		_strcpy(buffer, token);
		if (token[-1] != '\n')
			break;
	}
	free(token);
	if (len == -1)
		return (NULL);
	return (buffer);
}
