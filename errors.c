#include "monty.h"

/**
 * err_handler - Handles errors in the Monty interpreter and exits.
 * @err_code: Error code indicating the type of error.
 * Error Codes:
 *   1: Incorrect Usage
 *   2: File Open Error
 *   3: Unknown Instruction
 *   4: Memory Allocation Failure
 *   5: Push Instruction Usage Error
 *   6: Empty Stack Error
 *   7: Pint Instruction Error (Empty Stack)
 *   8: Pop Instruction Error (Empty Stack)
 *
 * Prints error messages to stderr and exits with EXIT_FAILURE.
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
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(args, int));
			break;
		case 6:
			fprintf(stderr, "L%d: empty stack\n", va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(args, int));
			break;
		case 8:
			fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(args, int));
			break;
	}

	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * err_handler_2 - Handles specific errors in the Monty interpreter and exits.
 * @err_code: Error code indicating the type of error.
 * Error Codes:
 *   9: Can't Swap, Stack Too Short
 *   10: Can't Add, Stack Too Short
 *   11: Can't Sub, Stack Too Short
 *   12: Can't Mul, Stack Too Short
 *   13: Can't Div, Stack Too Short
 *   14: Can't Mod, Stack Too Short
 *   15: Division by Zero
 *   16: Can't Pchar, Stack Empty
 *   17: Can't Pchar, Value Out of Range
 *
 * Prints error messages to stderr and exits with EXIT_FAILURE.
 */

void err_handler_2(int err_code, ...)
{
	va_list args;

	va_start(args, err_code);
	switch (err_code)
	{

		case 9:
			fprintf(stderr, "L%d: can't swap, stack too short\n", va_arg(args, int));
			break;
		case 10:
			fprintf(stderr, "L%d: can't add, stack too short\n", va_arg(args, int));
			break;
		case 11:
			fprintf(stderr, "L%d: can't sub, stack too short\n", va_arg(args, int));
			break;
		case 12:
			fprintf(stderr, "L%d: can't mul, stack too short\n", va_arg(args, int));
			break;
		case 13:
			fprintf(stderr, "L%d: can't div, stack too short\n", va_arg(args, int));
			break;
		case 14:
			fprintf(stderr, "L%d: can't mod, stack too short\n", va_arg(args, int));
			break;
		case 15:
			fprintf(stderr, "L%d: division by zero\n", va_arg(args, int));
			break;
		case 16:
			fprintf(stderr, "L%d: can't pchar, stack empt\n", va_arg(args, int));
			break;
		case 17:
			fprintf(stderr, "L%d: can't pchar, value out of range\n",
					va_arg(args, int));
			break;
	}

	free_nodes();
	exit(EXIT_FAILURE);
}
