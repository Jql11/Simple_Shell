#include "main.h"

/**
 * _getbuiltin - check for buildin
 * @command: command
 * Return: 1 if found, 0 if not found
 */
int _getbuiltin(char *command[])
{
	int i = 0;
	mybuiltin builtin[] = {
		{"env", _env},
		{"exit", get_exit},
		{"cd", _cd},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL},
		};

	if (command == NULL)
		return (-1);
	while (builtin[i].name != NULL)
	{
		if (_strcmp(command[0], builtin[i].name) == 0)
		{
			builtin[i].func(command);
			return (1);
		}
		i++;
	}

	return (0);
}
