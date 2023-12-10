#include "main.h"

/**
	* finder - int func
	* Description: determines if prompt is cmd or filepath, then executes
	* @path_head: singly list of PATH directories
	* @user_cmds: array of "words" made from user's input
	* @first_arg: not necessary really (but I've added it anways)
	* Return: -1 on fail or 0
	*/
int finder(struct path *path_head, char **user_cmds, char *first_arg)
{
	struct path *tmp;
	int i;
	size_t pid;
	struct stat buffer;

	if (path_head == NULL || user_cmds == NULL || first_arg == NULL)
		return (-1);
	tmp = path_head;
	for (i = 0; first_arg[i] != '\0'; i++)
	{
		if (first_arg[i] == '/')
			break;
	}
	if (first_arg[i] != '\0')
	{
		if (stat(first_arg, &buffer) == -1)
			return (-1);
		pid = fork();
		if (pid == 0)
		{
			execve(first_arg, user_cmds, NULL);
		}
		wait(NULL);
	}
	else
	{
		printf("command is filename without path\n");
		if (file_finder(user_cmds, tmp) == -1)
			return (-1);
	}
	return (0);
}
