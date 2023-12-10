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

	buffer = malloc(200);
	if (buffer == NULL)
	{
		perror("Issue with allocating memory");
		return (NULL);
	}
	printf("$ ");
	while (1)
	{
		len = getline(&token, &buffsize, stdin);
		if (len == -1)
		{
			printf("Getline was passed ctrl+d\n");
			break;
		}
		printf("before token newlines have been removed %s\n", token);
		if (strcmp(token, "env\n") == 0)
			_env();
		if (strcmp(token, "exit\n") == 0)
			return (NULL);
		if (token[len - 1] == '\n')
		{
			token[len - 1] = '\0';
			printf("after removed newlines %s\n", token);
		}
		strcat(buffer, token);
		printf("buffer so far: %s\n", buffer);
		if (token[-1] != '\n')
			break;
	}
	printf("After getline\n");
	free(token);
	if (len == -1)
		return (NULL);
	return (buffer);
}
