#include "main.h"

/**
	* exe_finder - char *ptr func
	* Description: builds a singly linked list from path variable
	* @buffercpy: copy of the value of the PATH environment variable
	* Return: struct path *head so main func can access the list
	*/
struct path *exe_finder(char *buffercpy)
{
	struct path *head = NULL;
	char *dir = NULL;
	struct path *tmp = NULL;

	if (buffercpy == NULL)
		return (NULL);
	tmp = malloc(sizeof(struct path));
	head = tmp;
	dir = strtok(buffercpy, ":");
	if (dir == NULL)
		return (NULL);
	while (dir != NULL)
	{
		tmp->dir = dir;
		dir = strtok(NULL, ":");
		if (dir == NULL)
		{
			tmp->next = NULL;
			break;
		}
		tmp->next = malloc(sizeof(struct path));
		tmp = tmp->next;
	}
	return (head);
}
