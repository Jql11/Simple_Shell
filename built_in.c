#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
  *get_exit- exit function
  *@argv: argument
  *Return: 0 as a signal for the command loop to terminate
  */
int get_exit(__attribute__((unused))char **argv)
{
	return (0);
}
/**
  *_cd - change current directory
  *@argv: argument
  *Return: return 1
  */
int _cd(char **argv)
{
	if (argv[1] == NULL)
		perror("expected argument to \"cd\"");
	else
	{
		if (chdir(argv[1]) != 0)
			perror("err");
	}
	return (1);
}
/**
  *get_help - help
  *@argv: argument
  *Return: 1
  */
int get_help(char **argv)
{
	int i;

	for (i = 0; builtin[i].name != NULL; i++)
	{
		builtin_str[i].name;
	}
	return (1);
}
