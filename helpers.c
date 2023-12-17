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

/**
 * is_ascii - Checks if a given integer is within the ASCII range.
 *
 * @c: The integer to be checked.
 *
 * Return:
 *   1 if the integer is within the ASCII range (0 to 127), and 0 otherwise.
 */
int is_ascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
