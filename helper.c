#include "main.h"

/**
	* _strlen - int func
	* Description: determines length of string and returns it
	* @string: passed string
	* Return: length of string or -1 on fail (NULL pointer)
	*/
int _strlen(char *string)
{
	int i = 0;

	if (string == NULL)
		return (-1);
	while (string[i] != '\0')
		i++;

	return (i);
}
