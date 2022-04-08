#include "main.h"

/**
  * _strlen - returns the length of a string.
  * @s: string to check
  * Return: return the length.
  */
int _strlen(const char *s)
{
	int count = 0;

	while (*(s + count) != '\0')
		count++;

	return (count);
}

/**
 * _strncpy - copy the string
 *@dest: the pointer to the destination array
 *@src: the string to be copied
 *@n: the number of characters to be copied
 * Return: Always 0.
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (*(src + i) != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = ('\0');
		i++;
	}
	return (dest);
}
