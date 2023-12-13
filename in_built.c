#include "main.h"

/**
	* _exitter - void func
	* Description: exits shell with the passed code
	* @status: number to be passed into exit
	*/
void _exitter(char *status)
{
	int exit_status;

	if (status != NULL)
		exit_status = _atoi(status);
	else
		exit(0);
	if (exit_status == 0)
		perror("No chars present in exit status\n");
	if (exit_status == -1)
		perror("exit status has invalid chars\n");
	if (status > 0)
		exit(exit_status);
}
/**
	* _env - int func
	* Description: writes the environment to terminal
	*/
void _env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], _len(environ[i]));
		write(1, "\n", 2);
	}
}

/**
	* _setenv - void func
	* Description: sets a new variable / overwrites at name
	* @user_cmds: array of args from user
	*/
void _setenv(char **user_cmds)
{
	char *num;
	long int result;

	if (user_cmds[1] != NULL)
	{
		if (user_cmds[2] != NULL)
		{
			num = user_cmds[2];
			result = _atoi(num);
			if (result == -1)
				perror("Invalid chars in exit status\n");
			if (result == 0)
				perror("Bad value passed for setenv\n");
			else
				setenv(user_cmds[1], user_cmds[2], result);
		}
	}
	else
		perror("Incorrect number of args passed for setenv\n");
}

/**
	* _unsetenv - void func
	* Description: removes element at passed name
	* @envar: variable to be unset
	*/
void _unsetenv(char *envar)
{
	if (envar != NULL)
	{
		unsetenv(envar);
		return;
	}
	perror("Bad pointer - NULL");
}
