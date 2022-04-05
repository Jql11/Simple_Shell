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

/* string manipulation */
int _strlen(char *s);/* returns the length of a string.*/
char *_strdup(char *str);/* return a pointer to the new string */
int _strcmp(char *s1, char *s2);/* compare 2 strings */
char *_strcat(char *dest, char *src)/*concatenates two strings*/
/* get the whole path including the path and filename */
char *_getpath(char *envirname, char *command);

#endif
