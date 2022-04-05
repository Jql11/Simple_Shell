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

	command = malloc(sizeof(*command));
	if (command == NULL)
		return (NULL);
	token = strtok(buffer, " \t\n\r");
	for (i = 0; i < 16 && token != NULL; i++)
	{
		command[i] = token;
		token = strtok(NULL, " \t\n\r");
	}
	command[i] = NULL;

	return (command);
}

/**
 * getexecve - use execve to run the command
 * @command: command
 * @argv: argv[0]
 * @envp: environment path
 * Return: 1 if failed, otherwise return 0
 */
int getexecve(char *command[], char *argv[], char *envp[])
{
	pid_t child;
	struct stat st;
	char *commandWithPath;

	child = fork();
	if (child == -1)
	{
		printf("ERROR: child process fail\n");
		return (1);
	}
	if (child == 0)
	{
		if (stat(command[0], &st) != 0)
		{
			commandWithPath = _getpath("PATH", command[0]);
			if (commandWithPath)
			{
				command[0] = commandWithPath;
				if (execve(command[0], command, envp) == -1)
				{
					perror(argv[0]);
					exit(0);
				}
			}
		}
		else
		{
			if (execve(command[0], command, envp) == -1)
			{
				perror(argv[0]);
				exit(0);
			}
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
	unsigned int i;
	char *ret = NULL;
	int len;

	len = strlen(name);
	i = 0;
	while (environ[i])
	{
		ret = strstr(environ[i], name);
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
	char *token, *pathname;
	char *path[32];
	int i, j, count = 0;
	struct stat st;
	char *environment = _getenv(envirname);


	token = strtok(environment, ":");
	for (i = 0; i < 32 && token != NULL; i++)
	{
		path[i] = token;
		count++;
		token = strtok(NULL, ":");
	}
	for (j = 0; j < count; j++)
	{
		pathname = _strdup(path[j]);
		pathname = strcat(pathname, "/");
		pathname = strcat(pathname, command);
		if (stat(pathname, &st) == 0)
			return (pathname);
	}
	return (NULL);
}
