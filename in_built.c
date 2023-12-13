#include "main.h"

/**
	* _exitter - void func
	* Description: exits shell with the passed code
	* @status: number to be passed into exit
	*/
void _exitter(char *status)
{
	char **err = malloc(sizeof(char *));
	int exit_status;

	*err = malloc(sizeof(char *));
	if (status != NULL)
		exit_status = strtol(status, err, 10);
	else
		exit(0);
	if (status == 0)
		perror("No chars present in exit status\n");
	if (**err != '\0')
		perror("exit status has invalid chars\n");
	if (status > 0)
		exit(exit_status);
	free(*err);
	free(err);
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
	char **err = malloc(sizeof(char *));
	long int result;

	*err = malloc(sizeof(char *));
	if (user_cmds[1] != NULL)
	{
		if (user_cmds[2] != NULL)
		{
			num = user_cmds[2];
			result = strtol(num, err, 10);
			if (result == 0 || **err != '\0')
			{
				perror("Bad value passed for setenv\n");
			}
			else
				setenv(user_cmds[1], user_cmds[2], result);
		}
	}
	else
		perror("Incorrect number of args passed for setenv\n");
	free(err);
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
