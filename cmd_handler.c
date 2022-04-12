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

char **getcommands(char *buffer)
{
	char *token;
	char **command;
	int i;

	command = malloc((sizeof(char *)) * _strlen(buffer));
	if (command == NULL)
		return (NULL);
	token = strtok(buffer, " \t\n\r");
	if (token == NULL)
	{
		free(command);
		return (NULL);
	}
	for (i = 0; i < 16 && token != NULL; i++)
	{
		command[i] = token;
		token = strtok(NULL, " \t\n\r");
	}
	command[i] = NULL;

	return (command);
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
				command[0] = commandWithPath;
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
		_puts("ERROR: child process fail\n");
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
	{
		wait(NULL);
	}

	return (0);
}

/**
 * _getenv - get the environment
 * @name: environemnt name
 * Return: evironment
 */

char *_getenv(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		while (name[j])
		{
			if (name[j] != environ[i][j])
				break;

			j++;
		}
		if (name[j] == '\0' && environ[i][j] == '=')
		{
			value = (environ[i] + j + 1);
			return (value);
		}
	}
	return (0);
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
	char *environment = _getenv(envirname);

	environhold = malloc(_strlen(environment) + 1);
	if (environhold == NULL)
		return (NULL);
	_strncpy(environhold, environment, _strlen(environment) + 1);
	token = strtok(environhold, ":");
	if (token == NULL)
	{
		free(environhold);
		perror("Allocation error");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < 32 && token != NULL; i++)
	{
		path[i] = token;
		count++;
		token = strtok(NULL, ":");
	}
	free(token);
	free(environhold);
	for (j = 0; j < count; j++)
	{
		pathname = _strdup(path[j]);
		pathname = _strcat(pathname, "/");
		pathname = _strcat(pathname, command);
		if (stat(pathname, &st) == 0)
		{
			return (pathname);
		}
		free(pathname);
	}
	return (NULL);
}
