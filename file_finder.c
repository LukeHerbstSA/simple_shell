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
	int i = 0;
	char dir_sym[2] = "/";
	struct stat buffer;

	first_arg = malloc(_strlen(user_cmds[0] + 1));
	strcpy(first_arg, user_cmds[0]);
	pid = fork();
	if (pid == 0)
	{
		while (tmp != NULL)
		{
			user_cmds[0] = realloc(user_cmds[0], _strlen(tmp->dir) + 1);
			strcpy(user_cmds[0], tmp->dir);
			strcat(user_cmds[0], dir_sym);
			strcat(user_cmds[0], first_arg);
			if (stat(user_cmds[0], &buffer) != 1)
				execve(user_cmds[0], user_cmds, NULL);
			tmp = tmp->next;
		}
		printf("%s: not found\n", first_arg);
	}
	wait(NULL);
	free(first_arg);
	if (tmp == NULL)
		return (-1);
	return (0);
}
