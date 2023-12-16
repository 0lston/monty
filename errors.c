#include "monty.h"

/**
 * err_handler - Handles errors in the Monty interpreter and exits.
 *
 * @err_code: Error code indicating the type of error.
 *
 * Error Codes:
 *   1: Incorrect Usage
 *   2: File Open Error
 *   3: Unknown Instruction
 *   4: Memory Allocation Failure
 *   5: Push Instruction Usage Error
 *
 * This function prints error messages to stderr and exits with EXIT_FAILURE.
 */

void err_handler(int err_code, ...)
{
	int line_nbr;
	char *opcode;
	va_list args;

	va_start(args, err_code);
	switch (err_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(args, char *));
			break;
		case 3:
			line_nbr = va_arg(args, int);
			opcode = va_arg(args, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_nbr, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer", va_arg(args, int));
			break;
	}

	free_nodes();
	exit(EXIT_FAILURE);
}
