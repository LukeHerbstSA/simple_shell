#include "main.h"

/**
	* _interpreter - int func
	* Description: checks if a certain command is selected and execs
	* @user_cmds: array of args from user
	* Return: 1 on no specific cmd type, 0 if one is execed and -1 o fail
	*/
int _interpreter(char **user_cmds)
{
	char **err = malloc(sizeof(char *));
	long int status = 1;
	int check = 1;

	*err = malloc(sizeof(char *));
	if (strcmp(user_cmds[0], "env") == 0)
	{
		_env();
		check = 0;
	}
	if (strcmp(user_cmds[0], "exit") == 0)
	{
		check = 0;
		_exitter(user_cmds[1]);
		if (user_cmds[1] != NULL)
			status = strtol(user_cmds[1], err, 10);
		else
			exit(0);
		if (status == 0)
			perror("No chars present in exit status\n");
		if (**err != '\0')
			perror("exit status has invalid chars\n");
		if (status > 0)
			exit(status);
	}
	if (strcmp(user_cmds[0], "setenv") == 0)
	{
		_setenv(user_cmds);
		check = 0;
	}
	if (strcmp(user_cmds[0], "unsetenv") == 0)
	{
		_unsetenv(user_cmds[1]);
		check = 0;
	}
	free(*err);
	free(err);
	return (check);
}
