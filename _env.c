#include <unistd.h>
#include "main.h"
/**
  * _env - Prints the current environment
  * Return: void
  */
int _env(void)
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
