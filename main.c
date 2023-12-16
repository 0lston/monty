#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 *
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: 0 on successful execution.
 */

int main(int argc, char **argv)
{
	stack_t *head = NULL;

	if (argc != 2)
		err_handler(1);

	openFile(argv[1]);
	return (0);
}
