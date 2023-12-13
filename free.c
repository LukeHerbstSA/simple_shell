#include "main.h"

/**
	* _free - int func
	* Description: free cmd_args due to betty line limit requirements
	* @user_cmds: array of user args
	* @path_head: struct
	*/
void _free(char **user_cmds, struct path *path_head)
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
		user_cmds[i] = NULL;
		free(user_cmds);
	}
	while (path_head != NULL)
	{
		prev = path_head;
		path_head = path_head->next;
		prev->dir = NULL;
		free(prev);
	}
	if (path_head != NULL)
		free(path_head);
}
