#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"


/**
 * getcommands - get the commands from the command line
 * @buffer: - command line
 * Return: an array of commands
 */

/*
char **getcommands(char *buffer)
{
	char *token;
	char **command;
	int i;

	command = malloc(sizeof(*command));
	if (command == NULL)
		return (NULL);
	token = strtok(buffer, " \t\n\r");
	if (token == NULL)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < 16 && token != NULL; i++)
	{
		command[i] = token;
		token = strtok(NULL, " \t\n\r");
	}
	command[i] = NULL;

	return (command);
}
*/
char **getcommands(char *buffer)
{
	char **token_holder;
	char *token;
	unsigned int length;
	int i;

	buffer[_strlen(buffer) - 1] = '\0';
	length = _strlen(buffer);
	if (length == 0)
		return (NULL);
	token_holder = malloc((sizeof(char *)) * (length + 1));
	if (token_holder == NULL)
		return (NULL);
	i = 0;
	token = strtok(buffer, " \t\n\r");
	while (token != NULL)
	{
		token_holder[i] = malloc(_strlen(token) + 1);
		if (token_holder[i] == NULL)
		{
			free(token_holder);
			return (NULL);
		}
		_strncpy(token_holder[i], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
		++i;
	}
	token_holder[i] = NULL;
	return (token_holder);

}

/**
 * getexecve - use execve to match the command
 * @command: command
 * @argv: argv[0]
 * @envp: environment path
 * Return: 1 if failed, otherwise return 0
 */
int getexecve(char *command[], char *argv[], char *envp[])
{
	struct stat st;
	char *commandWithPath;

	if (_getbuiltin(command) == 0)
	{
		if (stat(command[0], &st) != 0)
		{
			commandWithPath = _getpath("PATH", command[0]);
			if (commandWithPath)
			{
				command[0] = commandWithPath;
			}
			else
				perror(argv[0]);
		}
			_fork(command, argv, envp);
	}
	return (1);
}

/**
  *_fork - fork
  * @command: command
  * @argv: argv
  * @envp: envp
  * Return: 0
  */
int _fork(char *command[], char *argv[], char *envp[])
{
	pid_t child;

	child = fork();
	if (child == -1)
	{
		printf("ERROR: child process fail\n");
		return (1);
	}
	if (child == 0)
	{
		if (execve(command[0], command, envp) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(NULL);
	return (0);
}

/**
 * _getenv - get the environment
 * @name: environemnt name
 * Return: evironment
 */

char *_getenv(const char *name)
{
	unsigned int i = 0;
	char *ret = NULL;
	int len;

	len = _strlen(name);
	while (environ[i])
	{
		ret = _strstr(environ[i], name);
/*		printf("environ[%d] is %s\n", i, environ[i]);*/
		if (ret)
			return (ret + len + 1);
		i++;
	}

	return (NULL);
}

/**
 * _getpath - get the whole path including the path and filename
 * @envirname: environment name
 * @command: filename got from command line
 * Return: path including path and filename
 */
char *_getpath(char *envirname, char *command)
{
	char *token, *pathname, *environhold;
	char *path[32];
	int i, j, count = 0;
	struct stat st;
	char *environment = getenv(envirname);

	environhold = malloc(_strlen(environment) + 1);
	if (environhold == NULL)
		return (NULL);
	_strncpy(environhold, environment, _strlen(environment) + 1);
	token = strtok(environhold, ":");
	if (token == NULL)
	{
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < 32 && token != NULL; i++)
	{
		path[i] = token;
		count++;
		token = strtok(NULL, ":");
	}
	for (j = 0; j < count; j++)
	{
		pathname = strdup(path[j]);
		pathname = strcat(pathname, "/");
		pathname = strcat(pathname, command);
		if (stat(pathname, &st) == 0)
			return (pathname);
	}
	return (NULL);
}
