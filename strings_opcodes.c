#include "monty.h"

/**
 * pall - Prints all values on the stack, starting from the top.
 *
 * @node: Pointer to the stack.
 * @line_nbr: Unused parameter (required for function pointer compatibility).
 */

void pall(stack_t **node,  __attribute__((unused))unsigned int line_nbr)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL)
		return;
	tmp = *node;
	while (tmp)
	{
		printf("%d\n", (tmp->n));
		tmp = tmp->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the pint instruction.
 *
 * This function prints the value at the top of the stack. If the stack is
 * empty, it calls the err_handler_2 function to handle the error.
 */

void pint(stack_t **node, unsigned int line_nbr)
{
	if (node == NULL || *node == NULL)
		err_handler(6, line_nbr);

	printf("%d\n", (*node)->n);
}

/**
 * nop - Does nothing.
 *
 * @node: Unused parameter (required for function pointer compatibility).
 * @line_nbr: Unused parameter (required for function pointer compatibility).
 *
 * This function does nothing and returns.
 */

void nop(stack_t **node, unsigned int line_nbr)
{
	(void)node;
	(void)line_nbr;
}

/**
 * pchar - Prints the ASCII value at the top of the stack as a character.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the pchar instruction.
 *
 * This function prints the ASCII value at the top of the stack as a character.
 * If the stack is empty or the value is not an ASCII character, it calls
 * the err_handler_2 function to handle the error.
 */

void pchar(stack_t **node, unsigned int line_nbr)
{
	if (node == NULL || *node == NULL)
		err_handler_2(15, line_nbr);
	if (!is_ascii((*node)->n))
		err_handler_2(16, line_nbr);

	printf("%c\n", (*node)->n);

}

/**
 * pstr - Prints the ASCII values on the stack as a string.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the pstr instruction.
 *
 * This function prints the ASCII values on the stack as a string until a
 * non-ASCII character or the end of the stack is encountered.
 */

void pstr(stack_t **node, __attribute__((unused))unsigned int line_nbr)
{
	stack_t *tmp = *node;

	while (tmp && is_ascii(tmp->n) && tmp->n != 0)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}

