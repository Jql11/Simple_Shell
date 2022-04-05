#ifndef MAIN_H
#define MAIN_H

extern char **environ;

/* get the commands from the command line */
char **getcommands(char *buffer);

/* use execve to run the command */
int getexecve(char *command[], char *argv[], char *envp[]);

/* returns the length of a string.*/
int _strlen(char *s);

/* return a pointer to the new string */
char *_strdup(char *str);

/* get the whole path including the path and filename */
char *_getpath(char *envirname, char *command);

#endif
