#include "monty.h"

/**
 * is_number - Checks if a string is a valid number.
 *
 * @str: The string to be checked.
 *
 * Return: 1 if @str is a number, 0 otherwise.
 */

int is_number(char *str)
{
	int i = 0;

	if (str[i] == '-')
		i++;
	for (; str[i]; i++)
		if (!isdigit(str[i]))
			return (0);
	return (1);
}
