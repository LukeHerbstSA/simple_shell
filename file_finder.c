#include "main.h"

/**
	* file_finder - int func
	* Description: Concatenates command onto PATH exec paths
	* @user_cmds: array of user args
	* @tmp: pointer to struct
	* Return: always 0
	*/
int file_finder(char **user_cmds, struct path *tmp)
{
	size_t pid;
	char *first_arg = NULL;
	char dir_sym[2] = "/";
	struct stat buffer;

	first_arg = malloc(_len(user_cmds[0]) + 1);
	_strcpy(first_arg, user_cmds[0]);
	pid = fork();
	if (pid == 0)
	{
		while (tmp != NULL)
		{
			user_cmds[0] = realloc(user_cmds[0], _len(tmp->dir) + _len(first_arg) + 2);
			_strcpy(user_cmds[0], tmp->dir);
			_strcat(user_cmds[0], dir_sym);
			_strcat(user_cmds[0], first_arg);
			if (stat(user_cmds[0], &buffer) != 1)
				execve(user_cmds[0], user_cmds, environ);
			tmp->dir = NULL;
			tmp = tmp->next;
		}
	}
	wait(NULL);
	if (tmp == NULL)
	{
		write(2, first_arg, _len(first_arg) + 1);
		write(2, ": not found\n", 13);
		exit(127);
	}
	free(first_arg);
	return (0);
}
