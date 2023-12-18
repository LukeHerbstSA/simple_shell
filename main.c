#include "main.h"
#include <fcntl.h>

/**
	* main - int function
	* Description: loop that only breaks on error, to return int code to main
	* @argc: num of args
	* @argv: array args
	* Return: always -1 (when closed)
	*/
int main(int argc, char **argv)
{
	char **user_cmds = NULL;
	char *buffer = NULL;
	struct path *path_head = NULL;
	int descriptor = 0;
	int i;

	if (argc == 2)
	{
		descriptor = open(argv[1], O_RDONLY, "r");
		if (descriptor == -1)
			exit(1);
	}
	while (1)
	{
		while (1) /* Error codes may need a specific way to deal with them */
		{
			if (descriptor <= 2 && isatty(STDIN_FILENO))
				_putchar_string("$ ");
			buffer = prompt();
			if (buffer == NULL)
				return (0);
			printf("After buffer: %s\n", buffer);
			user_cmds = tokenizer(buffer);
			if (user_cmds == NULL)
				break;
			for (i = 0; user_cmds[i] != NULL; i++)
				printf("user_cmds[i] = %s\n", user_cmds[i]);
			path_head = exe_finder();
			if (path_head == NULL)
				break;
			if ((_strcmp(user_cmds[0], "") == 0) || (_strcmp(user_cmds[0], " ") == 0))
				break;
			if (_interpreter(user_cmds) <= 0)
				break;
			finder(path_head, user_cmds, user_cmds[0]);
			break;
		}
		_free(user_cmds, path_head);
	}
	return (0);
}
