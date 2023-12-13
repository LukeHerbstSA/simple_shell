#include "main.h"

/**
	* _atoi - int func
	* Description: primitive atoi to handle str to int conversion
	* @string: string to be converted to int
	* Return: the int conversion (only handles pos nums), -1 on fail
	*/
int _atoi(char *string)
{
	int i = 0;
	int num = 1;

	if (string == NULL)
		return (-1);
	if ((string[0] < 48) || (string[0] > 57))
		return (-1);
	if (_strcmp(string, " ") == 0)
		return (0);
	while (string[i] != '\0')
	{
		num = num + (string[i] - 48);
		i++;
		if (string[i] != '\0')
		{
			if (string[i] >= 48 && string[i] <= 57)
				num = num * 10;
			else
				return (-1);
		}
	}
	return (num);
}
