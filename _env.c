#include <unistd.h>
#include <stdio.h>
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
