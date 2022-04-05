#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
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
