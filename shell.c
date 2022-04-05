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
	char *buffer = NULL;
	size_t bufsize = 32;
	char **command;

	if(ac < 1)
	{
		printf("Invalid input.\n");
		exit(1);
	}

	buffer = (char *)malloc(sizeof(*buffer));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}
	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&buffer, &bufsize, stdin) == -1)
		{
			printf("\n");
			free(buffer);
			break;
		}
		command = getcommands(buffer);
		getexecve(command, argv, envp);
	}
	free(buffer);
	exit(0);
}
