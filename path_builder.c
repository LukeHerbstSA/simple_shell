#include "main.h"

/**
	* exe_finder - char *ptr func
	* Description: builds a singly linked list from path variable
	* Return: struct path *head so main func can access the list
	*/
struct path *exe_finder(void)
{
	struct path *head;
	char *buffer;
	char *buffercpy = NULL;
	char *dir;
	struct path *tmp = NULL;

	buffer = getenv("PATH");
	buffercpy = malloc(strlen(buffer) + 1);
	strcpy(buffercpy, buffer);
	tmp = malloc(sizeof(struct path));
	head = tmp;
	printf("peaking at buffer before splitting: %s\n", buffer);
	dir = strtok(buffercpy, ":");
	if (buffer == NULL || tmp == NULL || dir == NULL)
		return (NULL);
	while (dir != NULL)
	{
		printf("%s\n", dir);
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
	free(buffercpy);
	return (head);
}
