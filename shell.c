#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include "main.h"

/**
 * main - main function
 * @ac: number of arguments
 * @argv: array of arguments
 * @envp: array of environment path
 * Return: Always 0.
 */

int main(int ac, char *argv[], char *envp[])
{
	char *buffer;
	size_t bufsize = 32;
	int i;
	char **command;

	if (ac < 1)
	{
		_puts("Invalid input.\n");
		exit(1);
	}

	buffer = malloc(sizeof(char *) * bufsize);
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("#cisfun$ ");
			signal(SIGINT, ctrl_c);
		}
		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			free(buffer);
			ctrl_d();
			break;
		}

		command = getcommands(buffer);
		if (command)
			getexecve(command, argv, envp);
		else
			continue;
	}
	free(buffer);
	for (i = 0; command[i] != NULL; i++)
		free(command[i]);
	free(command);
	exit(0);
}
