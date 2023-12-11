#include "main.h"

/**
	* main - int function
	* Description: loop that only breaks on error, to return int code to main
	* Return: always -1 (when closed)
	*/
int main(void)
{
	char **user_cmds = NULL;
	char *buffer = NULL;
	char *first_arg = NULL;
	struct path *path_head = NULL;

	while (1)
	{
		while (1) /* Error codes may need a specific way to deal with them */
		{
			buffer = prompt();
			if (buffer == NULL)
			{
				printf("\nClosing shell . . .\n");
				return (-1);
			}
			user_cmds = tokenizer(buffer);
			if (user_cmds == NULL)
			{
				perror("Something went wrong with the command you gave\n");
				break;
			}
			path_head = exe_finder();
			if (path_head == NULL)
			{
				perror("Something went wrong when building your PATH\n");
				break;
			}
			if (_interpreter(user_cmds) <= 0)
				break;
			first_arg = user_cmds[0];
			if (finder(path_head, user_cmds, first_arg) == -1)
				break;
			break;
		}
		_free(user_cmds, path_head);
	}
}
