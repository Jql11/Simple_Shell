#include <stdio.h>
#include "main.h"

/**
  * _strlen - returns the length of a string.
  * @s: string to check
  * Return: return the length.
  */
int _strlen(const char *str)
{
	int count = 0;

	while (*(str + count) != '\0')
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

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - write the string to stdout
 * @str: string to write
 * Return: 0 if success, EOF if an error
 */
int _puts(char *str)
{
	while (*str)
	{
		if (_putchar(*str++) == EOF)
			return (EOF);
	}

	return (0);
}
