#include "main.h"

/**
 * _isdigit - checks for a digit (0 through 9).
 * @c: character or number
 * Return: 1 if c is a digit, 0 otherwise
 */
int _isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
  * _atoi - convert string to int (str only has numbers)
  * @s: string to be converted
  * Return: int
  */
int _atoi(char *s)
{
	int integer, i = 0;

	while (*(s + i))
	{
		integer = integer * 10 + *(s + i) - '0';
		i++;
	}
	return (integer);
}
