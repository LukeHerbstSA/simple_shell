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
	* _getenv - char ptr func
	* Description: returns ptr to requested env var
	* @envar: desired environment variable
	* Return: char ptr to requested environment variable
	*/
char *_getenv(char *envar)
{
	int i = 0;
	int j;

	while (environ[i] != NULL)
	{
		j = 0;
		while (environ[i][j] != '=')
		{
			if (envar[j] != environ[i][j])
				break;
			j++;
		}
		if (environ[i][j] == '=')
			return (&environ[i][j++]);
		i++;
	}
	return (NULL);
}
/**
	* _setenv - void func
	* Description: sets a new variable / overwrites at name
	* @user_cmds: array of args from user
	*/
void _setenv(char **user_cmds)
{
}

/**
	* _unsetenv - void func
	* Description: removes element at passed name
	* @envar: variable to be unset
	*/
void _unsetenv(char *envar)
{
}
