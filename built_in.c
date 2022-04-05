#include "main.h"
#include <unistd.h>
#include <stdio.h>
int get_exit(char **argv);
int _env(char **argv);
int _cd(char **argv);

char *builtin_str[] = {"exit", "env", "cd"};
int (*builtin_func[]) (char **) = {&get_exit, &_env, &_cd};
int num_builtin(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}

int builtin_execute(char **argv)
{
	int i;
	if (argv[0] == NULL)
		return (1);
	for (i = 0; i < num_builtin(); i++)
	{
		if (_strcmp(argv[0], builtin_str[i]) == 0)
			return (*builtin_func[i](argv));
	}
	return (getexecve(command, argv, envp));
}
/**
  * _env - Prints the current environment
  * Return: void
  */
int _env(char **argv)
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
int get_exit(char **argv)
{
	return (0);
}
/**
  *_cd - change current directory
  *@args: argument
  *return: return 1
  */
int _cd(char **argv)
{
	if (argv[1] == NULL)
	{
		fprintf(stderr, "lsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(argv[1]) != 0)
			perror("err");
	}
	return (1);
}
