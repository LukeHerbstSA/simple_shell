#include "main.h"

/**
	* _putchar_string - void func
	* Description: putchars passed string
	* @string1: passed string
	*/
void _putchar_string(char *string1)
{
	int i = 0;

	if (string1 == NULL)
		return;
	while (string1[i] != '\0')
	{
		putchar(string1[i]);
		i++;
	}
}
/**
	* _len - int func
	* Description: determines length of string and returns it
	* @string: passed string
	* Return: length of string or -1 on fail (NULL pointer)
	*/
int _len(char *string)
{
	int i = 0;

	if (string == NULL)
		return (-1);
	while (string[i] != '\0')
		i++;

	return (i);
}

/**
	* _strcpy - void func
	* Description: overwrites string 1 with string 2
	* @string1: overwritee
	* @string2: overwriter
	*/
void _strcpy(char *string1, char *string2)
{
	int i;

	if (string1 == NULL || string2 == NULL)
		return;
	for (i = 0; string2[i] != '\0'; i++)
		string1[i] = string2[i];
	string1[i] = '\0';
}

/**
	* _strcat - void func
	* Description: copies string 2 onto the end of string 1
	* @string1: receiver
	* @string2: donor
	*/
void _strcat(char *string1, char *string2)
{
	int i = 0;
	int j;

	if (string1 == NULL || string2 == NULL)
		return;
	while (string1[i] != '\0')
		i++;
	for (j = 0; string2[j] != '\0'; j++)
	{
		string1[i] = string2[j];
		i++;
	}
	string1[i] = '\0';
}

/**
	* _strcmp - int func
	* Description: checks if string1 is the same as string 2
	* @string1: matcher
	* @string2: matchee
	* Return: 1 if not matching, 0 if matched
	*/
int _strcmp(char *string1, char *string2)
{
	int i = 0;

	while (string1[i] != '\0')
	{
		if (string1[i] != string2[i])
			return (1);
		i++;
	}
	if (string2[i] != '\0')
		return (1);
	return (0);
}
