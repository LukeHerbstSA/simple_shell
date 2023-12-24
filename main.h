#ifndef MAIN_H

#define MAIN_H

#include <signal.h>
#include <sys/wait.h>
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

char *_getenv(char *env_variable);
int _atoi(char *number);
void _putchar_string(char *line);
int _strcmp(char *matcher, char *matchee);
void _strcat(char *reciever, char *donor);
void _strcpy(char *srtring1, char *string2);
int _len(char *string);
void _setenv(char **user_cmds);
void _unsetenv(char *envar);
int _interpreter(char **user_cmds);
void _env(void);
char **tokenizer(char *buffer);
void _free(char **user_cmds, struct path *path_head, char *buffercpy, int exit_code);
char *prompt(void);
struct path *exe_finder(char *env_cpy);
int finder(struct path *path_head, char **user_cmds, char *first_arg);
int file_finder(char **user_cmds, struct path *path_head);

#endif
