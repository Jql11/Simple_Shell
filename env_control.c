#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
  * _env - Prints the current environment
  * @command: command
  * Return: void
  */
int _env(__attribute__((unused))char *command[])
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
/**
 * commandlen - check the numbers of commands
 * @command: pointer to the command array
 * Return: number of commands
 */
int commandlen(char *command[])
{
	int count = 0;

	while (command[count] != NULL)
		count++;
	return (count);
}

/**
 * _setenv - set the environment variable
 * @command: command
 * Return: 0 if success, -1 if fail
 */
int _setenv(char *command[])
{
	char *name = NULL, *value = NULL, *env;
	int i = 0;

	if (commandlen(command) != 3)
	{
		perror("Error");
		return (-1);
	}
	printf("in function setenv\n");
	name = command[1];
	value = command[2];
	printf("name is %s\n", name);
	printf("value is %s\n", value);
	env = malloc(sizeof(*env));
	if (env == NULL)
		return (-1);
	env = _strdup(name);
	env = _strcat(env, "=");
	env = _strcat(env, value);
	while (environ[i] != NULL && _strstr(environ[i], name) == NULL)
	{
		i++;
	}
	if (environ[i] == NULL)
	{
		environ[i] = env;
		environ[i + 1] = NULL;
	}
	else
	{
		environ[i] = env;
	}
	free(env);
	return (0);
}

/**
 * _unsetenv - remove the environment variable
 * @command: command
 * Return: -1 if fail, 0 if success
 */
int _unsetenv(char *command[])
{
	int i, index;
	char *env;

	if (commandlen(command) != 2)
	{
		perror("Error");
		return (-1);
	}
	for (i = 0; environ[i]; i++)
	{
		env = _strstr(environ[i], command[1]);
		if (env != NULL)
		{
			index = i;
		}
		if (i >= index)
		{
			environ[i] = environ[i + 1];
		}
	}

	return (0);
}
