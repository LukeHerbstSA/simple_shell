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

	printf("Start of free function function\n");
	while (user_cmds[i] != NULL)
	{
		free(user_cmds[i]);
		i++;
	}
	free(user_cmds[i]);
	free(user_cmds);
	printf("After user_cmds has been freed\n");
	while (path_head != NULL)
	{
		printf("Current dir: %s\n", path_head->dir);
		prev = path_head;
		path_head = path_head->next;
		printf("Before free");
		printf("After freeing prev->dir\n");
		free(prev);
		printf("After freeing prev\n");
	}
	printf("After path_head has been freed\n");
	free(path_head);
}
