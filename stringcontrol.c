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

/**
 * _strcat - concatenates two strings
 *@src: string to be copied
 *@dest: string copy to
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	while (*(dest + j) != '\0')
	{
		j++;
	}

	while (*(src + i) != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
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
char *_strstr(char *haystack, char *needle)
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
