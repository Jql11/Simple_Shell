#include <stdlib.h>
#include "main.h"

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
	for (i = 0; i <= length; i++)
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
		i++;
	}
	return (0);
}

/**
  * str_concat - concatenate two strings
  * @s1: string 1
  * @s2: string 2
  * Return: return the string containing s1 and s2
  */
char *_strcat(char *s1, char *s2)
{
	int length1;
	int length2;
	char *newStr;
	int i, j;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	length1 = _strlen(s1);
	length2 = _strlen(s2);
	newStr = malloc((length1 + length2 + 1) * sizeof(char));
	if (newStr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		newStr[i] = s1[i];
		i++;
	}
	j = 0;
	while (j <= length2)
	{
		newStr[i] = s2[j];
		i++;
		j++;
	}
	return (newStr);
}

/**
 *compare - compare strings
 *@X: string 1
 *@Y: substring
 *Return: value
 */
int compare(const char *X, const char *Y)
{
	while (*Y != '\0')
	{
		if (*X != *Y)
		{
			return (0);
		}
		X++;
		Y++;
	}
	return (1);
}
/**
* _strstr - searches a string for any of a set of bytes
* @haystack: initial string
* @needle: substring containing the charcters in haystack
* Return: a pointer to the beginning of the located substring
*/
char *_strstr(char *haystack, const char *needle)
{
	if (*needle == '\0')
		return (haystack);
	while (*haystack != '\0')
	{
		if (*haystack == *needle)
		{
			if (compare(haystack, needle) == 1)
				return (haystack);
		}
		haystack++;
	}
	return (NULL);
}
