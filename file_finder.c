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

	first_arg = malloc(strlen(user_cmds[0] + 1));
	strcpy(first_arg, user_cmds[0]);
	printf("Args in user_cmds before searching through directories: \n");
	printf("user_cmds[0]: %s\n", first_arg);
	if (user_cmds[1] != NULL)
		printf("user_cmds[1]: %s\n", user_cmds[1]);
	pid = fork();
	if (pid == 0)
	{
		while (tmp != NULL)
		{
			printf("Test User_cmds[1]: %s\n", user_cmds[1]);
			printf("Dir: %s\n", tmp->dir);
			user_cmds[0] = realloc(user_cmds[0], strlen(tmp->dir) + 1);
			strcpy(user_cmds[0], tmp->dir);
			printf("Test2 User_cmds[1]: %s\n", user_cmds[1]);
			strcat(user_cmds[0], dir_sym);
			printf("Test3 User_cmds[1]: %s\n", user_cmds[1]);
			strcat(user_cmds[0], first_arg);
			printf("user_cmds[0]: %s\nuser_cmds[1]: %s\n", user_cmds[0], user_cmds[1]);
			if (stat(user_cmds[0], &buffer) != 1)
				execve(user_cmds[0], user_cmds, NULL);
			tmp = tmp->next;
		}
	}
	wait(NULL);
	free(first_arg);
	if (tmp == NULL)
		return (-1);
	printf("After searching the directories - user_cmds[1]: %s\n", user_cmds[1]);
	return (0);
}
