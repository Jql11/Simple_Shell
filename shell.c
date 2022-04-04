#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
/**
 * main - execve example
 *
 * Return: Always 0.
 */

int main(int ac,char *argv[], char *envp[])
{
	pid_t child;
	char *tok, *command[16];
	int status;
	char *buffer = NULL;
	size_t i, bufsize = 32;

	buffer = (char *)malloc(bufsize * sizeof(char));
    if(buffer == NULL)
    {
        perror("Unable to allocate buffer");
        exit(1);
    }
    while (1)
    {
    	printf("#cisfun$ ");
    	if  (getline(&buffer,&bufsize,stdin) == -1)
		break;
	tok = strtok(buffer, " \t\n\r");
	for (i = 0; i < 16 && tok != NULL; i++)
	{
		command[i] = tok;
		tok = strtok(NULL, " \t\n\r");
	}
	command[i] = NULL;
	child = fork();
    	if (child == -1)
    	{
	    printf("ERROR: child process fail\n");
	    return (1);
    	}
    	if (child == 0)
    	{
		if (execve(command[0], command, envp) == -1)
	    {
		    perror(argv[0]);
		    exit(EXIT_FAILURE);
	    }
    	}
    	else
		    wait(&status);
    }
    free(buffer);
    exit(status);
}

