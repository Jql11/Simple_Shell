#include "main.h"
#include <unistd.h>

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


/**
  *_exit- exit function
  *@args: argument
  *return: 0 as a signal for the command loop to terminate
  */
int _exit(char **args)
{
	return (0);
}
/**
  *_cd - change current directory
  *@args: argument
  *return: return 1
  */
int _cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1] != 0))
			perror("ERROR")；
	}
	return (1);
}
