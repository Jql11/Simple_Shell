#ifndef MAIN_H
#define MAIN_H

/* get the commands from the command line */
char **getcommands(char *buffer);

/* use execve to run the command */
int getexecve(char *command[], char *argv[], char *envp[]);



#endif
