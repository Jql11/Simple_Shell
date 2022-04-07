#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
  *get_exit- exit function
  *@command: command
  *Return: 0 as a signal for the command loop to terminate
  */
int get_exit(char *command[1])
{
	int i = 0;
	char digit;

	if (command[1] != NULL)
	{
		digit = _isdigit(command[1][i]);
		while (command[1][i])
		{
			if (digit == 1)
				i++;
			if (digit == 0)
				exit(132);
		}
		i = _atoi(command[1]);
	}
	exit(i);
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
		update_pwd(getenv("HOME"));
	}
	else if (argv[1][0] == '-' && argv[1][1] == '\0')
	{
		write(STDOUT_FILENO, getenv("OLDPWD"), _strlen(getenv("OLDPWD")));
		write(STDOUT_FILENO, "\n", 1);
		chdir(getenv("OLDPWD"));
	}
	else
	{
		if (update_pwd(argv[1]) != 0)
			perror("err");
	}
	return (1);
}

/**
 * update_pwd - update the pwd and old pwd
 * @pwd: pwd
 * Return: 0 if success, -1 if fail
 */
int update_pwd(char *pwd)
{
	char *oldDirectory, *oldDirectoryHold;
	char *value;
	char **setPWDCommand;
	char **setOLDPWDCommand;

	oldDirectory = getenv("PWD");
	oldDirectoryHold = malloc(_strlen(oldDirectory) + 1);
	if (oldDirectoryHold == NULL)
		return (-1);
	strcpy(oldDirectoryHold, oldDirectory);

	if (chdir(pwd) != 0)
		return (-1);

	value = getcwd(NULL, 0);
	setPWDCommand = malloc(sizeof(*setPWDCommand));
	if (setPWDCommand == NULL)
		return (-1);
	setPWDCommand[0] = "setenv";
	setPWDCommand[1] = "PWD";
	setPWDCommand[2] = value;
	_setenv(setPWDCommand);

	setOLDPWDCommand = malloc(sizeof(*setOLDPWDCommand));
	if (setOLDPWDCommand == NULL)
		return (-1);
	setOLDPWDCommand[0] = "setenv";
	setOLDPWDCommand[1] = "OLDPWD";
	setOLDPWDCommand[2] = oldDirectoryHold;
	_setenv(setOLDPWDCommand);

	free(setPWDCommand);
	free(setOLDPWDCommand);
	return (0);
}
/**
  *ctrl_c - make ctrl_c not working
  *@a: int for signal
  */
void ctrl_c(__attribute__((unused))int a)
{
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
