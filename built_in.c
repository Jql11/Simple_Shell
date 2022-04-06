#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/**
  *get_exit- exit function
  *@argv: argument
  *Return: 0 as a signal for the command loop to terminate
  */
int get_exit(__attribute__((unused))char **argv)
{
	printf("EXIT SUCCESS");
	exit(0);
}
/**
  *_cd - change current directory
  *@argv: argument
  *Return: return 1
  */
int _cd(char **argv)
{

	if (argv[1] == NULL || (argv[1][0] == '~' && argv[1][1] == '\0'))
	{
		chdir(_getenv("HOME"));
		setenv("PWD", getcwd(NULL, 0),1);
	}

	else if (argv[1][0] == '-' && argv[1][1] == '\0')
	{
		printf("%s\n", getenv("OLDPWD"));
		chdir(getenv("OLDPWD"));
	}
	else if (chdir(argv[1]) != 0)
			perror("err");
	else
	{
		chdir(argv[1]);
		setenv("PWD", getcwd(NULL, 0),1);
	}
	return (1);
}
/**
  *ctrl_c - make ctrl_c not working
  *@n: int for signal
  */
void ctrl_c(__attribute__((unused))int a)
{
	write(STDOUT_FILENO, "", 0);
}
