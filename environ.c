#include "main.h"

extern char **environ;

int _env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(1, environ[i], strlen(environ[i]));
		write(1, "\n", 2);
	}
	return (0);
}
