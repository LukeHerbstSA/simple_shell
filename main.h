#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

struct path
{
	char *dir;
	struct path *next;
};

int _env(void);
char **tokenizer(char *buffer);
void _free(char **user_cmds, struct path *path_head);
char *prompt(void);
struct path *exe_finder(void);
int finder(struct path *path_head, char **user_cmds, char *first_arg);
int file_finder(char **user_cmds, struct path *path_head);

#endif
