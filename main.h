#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
extern char **environ;

/* get the commands from the command line */
char **getcommands(char *buffer);

/* use execve to run the command */
int getexecve(char *command[], char *argv[], char *envp[]);

/* built-in function */
int _env(void);

/* self-create function */
int _strlen(char *s);

#endif
