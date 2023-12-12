#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;

/**
	* struct path - linked list of dirs
	* @dir: contains a single directory from path
	* @next: pointer to next node in path
	*
	* Description: contains directories from path for searching
	*/
struct path
{
	char *dir;
	struct path *next;
};

int _strlen(char *string);
void _exitter(char *status);
void _setenv(char **user_cmds);
void _unsetenv(char *envar);
int _interpreter(char **user_cmds);
void _env(void);
char **tokenizer(char *buffer);
void _free(char **user_cmds, struct path *path_head);
char *prompt(void);
struct path *exe_finder(void);
int finder(struct path *path_head, char **user_cmds, char *first_arg);
int file_finder(char **user_cmds, struct path *path_head);

#endif
