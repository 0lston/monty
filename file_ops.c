#include "monty.h"

/**
 * openFile - Opens a file and reads its contents.
 *
 * @filename: The name of the file to be opened.
 */

void openFile(const char *filename)
{
	FILE *fd = fopen(filename, "r");

	if (fd == NULL)
		err_handler(2, filename);

	readFile(fd);
	fclose(fd);
}

/**
 * readFile - Reads the contents of a file line by line.
 *
 * @fd: The file stream to be read.
 */

void readFile(FILE *fd)
{
	char *lineptr = NULL;
	size_t n = 0;
	int line_nbr = 1;
	int format = 0;

	while (getline(&lineptr, &n, fd) != -1)
	{
		parse_line(lineptr, line_nbr, &format);
		line_nbr++;
	}
	free(lineptr);
}

/**
 * parse_line - Parses a line into opcode and value.
 *
 * @lineptr: The string containing the line to be parsed.
 * @line_nbr: The line number being parsed.
 * @format: Pointer to an integer indicating stack or queue mode (0 or 1).
 */

void parse_line(char *lineptr, int line_nbr, int *format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	opcode = strtok(lineptr, delim);
	if (!opcode || opcode[0] == '#')
		return;

	if (strcmp(opcode, "queue") == 0)
	{
		*format = 1;
		return;
	}
	else if (strcmp(opcode, "stack") == 0)
	{
		*format = 0;
		return;
	}

	value = strtok(NULL, delim);
	get_function(opcode, value, line_nbr, format);

}

/**
 * get_function - Matches the opcode to a corresponding function.
 *
 * @opcode: The opcode to be matched.
 * @value: The value associated with the opcode.
 * @line_nbr: The line number being processed.
 * @format: Pointer to an integer indicating stack or queue mode (0 or 1).
 */

void get_function(char *opcode, char *value, int line_nbr, int *format)
{
	instruction_t func_list[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"nop", nop},
		{"add", _add},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;

	for (i = 0; func_list[i].opcode; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_f(func_list[i].f, opcode, value, line_nbr, format);
			break;
		}
	}
	if (!func_list[i].opcode)
		err_handler(3, line_nbr, opcode);
}


/**
 * call_f - Calls the corresponding function based on the opcode.
 *
 * @op_func: The function to be called.
 * @op: The opcode.
 * @value: The value associated with the opcode.
 * @line_nbr: The line number being processed.
 * @format: Pointer to an integer indicating stack or queue mode (0 or 1).
 */

void call_f(func op_func, char *op, char *value, int line_nbr, int *format)
{
	stack_t *node;
	int sign = 1;

	if (strcmp(op, "push") == 0)
	{
		if (value == NULL || !is_number(value))
			err_handler(5, line_nbr);
		if (value[0] == '-')
		{
			value++;
			sign = -1;
		}

		node = create_node(atoi(value) * sign);
		if (*format == 1)
			enqueue(&node, line_nbr);
		else
			op_func(&node, line_nbr);
	}
	else
		op_func(&head, line_nbr);
}
