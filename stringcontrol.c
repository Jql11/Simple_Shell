#include <stdlib.h>
#include "main.h"

/**
  * _strlen - returns the length of a string.
  * @s: string to check
  * Return: return the length.
  */
int _strlen(char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;

	return (count);
}

/**
  * _strdup - return a pointer to the new allocated memory address
  * @str: given string
  * Return: return the pointer to new string address
  */
char *_strdup(char *str)
{
	int length;
	int i;
	char *dupStr;

	if (str == NULL)
		return (NULL);
	length = _strlen(str);
	dupStr = malloc((length + 1) * sizeof(char));
	if (dupStr == NULL)
		return (NULL);
	for (i = 0; i < length; i++)
		dupStr[i] = str[i];

	return (dupStr);
}

/**
 * _strcmp - compares two strings.
 *
 * @s1:string 1
 * @s2:string 2
 * Return: copied string
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (*(s1 + i) != '\0' && *(s2 + i) != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		else
			i++;
	}
	return (0);
}
