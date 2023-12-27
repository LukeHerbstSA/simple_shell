#include "main.h"

/**
	* _free - int func
	* Description: free cmd_args due to betty line limit requirements
	* @user_cmds: array of user args
	* @path_head: struct
	* @buffercpy: copy of PATH env variable
	* @stat: exit status if applicable
	*/
void _free(char **user_cmds, struct path *path_head, char *buffercpy, int stat)
{
	int i = 0;
	struct path *prev;

	if (user_cmds != NULL)
	{
		while (user_cmds[i] != NULL)
		{
			free(user_cmds[i]);
			user_cmds[i] = NULL;
			i++;
		}
		free(user_cmds[i]);
		free(user_cmds);
	}
	user_cmds = NULL;
	while (path_head != NULL)
	{
		prev = path_head;
		path_head = path_head->next;
		prev->dir = NULL;
		free(prev);
	}
	if (path_head != NULL)
		free(path_head);
	free(buffercpy);
	if (stat >= 0)
	{
		exit(stat);
	}
}
