#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * main - prints the environment
 *
 * Return: Always 0.
 */

 char *_getenv(const char *name)
{
	extern char **environ;
	char *array[100], *token;
	int i = 0, j = 0;
	char *value = NULL;
	
	while (environ[j] != NULL)
	{
		token = strtok(environ[j], "=");
		while (token != NULL)
		{
			array[i] = token;
			if (strcmp(token, name) == 0)
			{
				token = strtok(NULL, "=");
				value = token;
				return (value);
			}

			token = strtok(NULL, "=");
			i++;
		}
		 array[i] = NULL;
		j++;
	}

	return (NULL);

} 

/* 3. PATH: Print each directory in PATH, one directory per line
int main(void)
{
	char *value = _getenv("PATH");
	char *token, *array[6];
	int i = 0;

	token = strtok(value, ":");
	while (i < 6 && token != NULL)
	{
		array[i] = token;
		printf("array[%d]:%s\n", i, token);
		token = strtok(NULL, ":");
		i++;
	}
	array[i] = NULL;
	return (0);
}*/

