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
