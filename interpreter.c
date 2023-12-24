#include "main.h"

/**
	* _interpreter - int func
	* Description: checks if a certain command is selected and execs
	* @user_cmds: array of args from user
	* Return: -2 if one is execed and -1 on no cmd or int>0 on exit code
	*/
int _interpreter(char **user_cmds)
{
	long int status = 1;
	int check = -1;

	if (_strcmp(user_cmds[0], "env") == 0)
	{
		_env();
		check = -2;
	}
	if (_strcmp(user_cmds[0], "exit") == 0)
	{
		if (user_cmds[1] != NULL)
			status = _atoi(user_cmds[1]);
		else
			status = 0;
		if (status == -1)
		{
			perror("Invalid chars present\n");
			check = -2;
		}
		if (status >= 0)
			return (status);
	}
	if (_strcmp(user_cmds[0], "setenv") == 0)
	{
		_setenv(user_cmds);
		check = -2;
	}
	if (_strcmp(user_cmds[0], "unsetenv") == 0)
	{
		_unsetenv(user_cmds[1]);
		check = -2;
	}
	return (check);
}
