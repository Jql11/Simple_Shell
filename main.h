#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
extern char **environ;

/**
 * struct builtin - link the command name to the function
 * @name: command received
 * @func: function
 */
typedef struct builtin
{
	char *name;
	int (*func)(char *[]);

} mybuiltin;

/* get the commands from the command line */
char **getcommands(char *buffer);
/* get the numbers of commands */
int commandlen(char *command[]);

/* use execve to run the command */
int getexecve(char *command[], char *argv[], char *envp[]);
/*use fork*/
int _fork(char *command[], char *argv[], char *envp[]);

/* get the environment variables */
char *_getenv(const char *name);

/* get the whole path including the path and filename */
char *_getpath(char *envirname, char *command);

/* built-in function */
int update_pwd(char *pwd);
int _cd(char **argv);
int get_exit(char *command[]);
void ctrl_c(int a);
void ctrl_d(void);
/* check if it is builtin */
int _getbuiltin(char *command[]);
/* print out environment variable */
int _env(__attribute__((unused))char *command[]);
/* set environment variables */
int _setenv(char *command[]);
/* remove environment variable */
int _unsetenv(char *command[]);

/* string manipulation */
/* returns the length of a string.*/
int _strlen(const char *s);
/* return a pointer to the new string */
char *_strdup(char *str);
/* compare 2 strings */
int _strcmp(char *s1, char *s2);
/* concatenates two strings*/
char *_strcat(char *dest, char *src);
/* returns pointer to first occurrence of the matched string in given string */
char *_strstr(char *haystack, const char *needle);
char *_strncpy(char *dest, char *src, int n);
/* integer manupilation */
/* check if char is a digit */
int _isdigit(char c);
/* convert string to chart */
int _atoi(char *s);
#endif
