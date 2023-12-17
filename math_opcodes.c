#include "monty.h"

/**
 * _add - Adds the top two elements of the stack.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the add instruction.
 *
 * This function adds the top two elements of the stack and replaces
 * them with the result. If the stack has fewer than two elements,
 * it calls err_handler_2 to handle the error.
 */

void _add(stack_t **node, unsigned int line_nbr)
{
	stack_t *tmp;

	if (*node == NULL || (*node)->next == NULL)
		err_handler_2(10, line_nbr);

	tmp = (*node)->next;

	tmp->n += (*node)->n;
	free(*node);
	*node = tmp;
}

/**
 * _sub - Subtracts the top element from the second top element of the stack.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the sub instruction.
 *
 * This function subtracts the top element from the second top element
 * of the stack and replaces them with the result. If the stack has
 * fewer than two elements, it calls err_handler_2 to handle the error.
 */

void _sub(stack_t **node, unsigned int line_nbr)
{
	stack_t *tmp;

	if (*node == NULL || (*node)->next == NULL)
		err_handler_2(11, line_nbr);

	tmp = (*node)->next;

	tmp->n -= (*node)->n;
	free(*node);
	*node = tmp;
}

/**
 * _mul - Multiplies the top two elements of the stack.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the mul instruction.
 *
 * This function multiplies the top two elements of the stack and replaces
 * them with the result. If the stack has fewer than two elements,
 * it calls err_handler_2 to handle the error.
 */

void _mul(stack_t **node, unsigned int line_nbr)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		err_handler_2(12, line_nbr);

	tmp = (*node)->next;

	tmp->n *= (*node)->n;
	free(*node);
	*node = tmp;
}

/**
 * _div - Divides the second top element by the top element of the stack.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the div instruction.
 *
 * This function divides the second top element by the top element of the
 * stack and replaces them with the result. If the stack has fewer than
 * two elements, it calls err_handler_2 to handle the error.
 */

void _div(stack_t **node, unsigned int line_nbr)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		err_handler_2(13, line_nbr);
	if ((*node)->n == 0)
		err_handler(15, line_nbr);

	tmp = (*node)->next;

	tmp->n /= (*node)->n;
	free(*node);
	*node = tmp;
}

/**
 * _mod - Computes the modulo of the second top element by the top element.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the mod instruction.
 *
 * This function computes the modulo of the second top element by the top
 * element of the stack and replaces them with the result. If the stack
 * has fewer than two elements, it calls err_handler_2 to handle the error.
 */

void _mod(stack_t **node, unsigned int line_nbr)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		err_handler_2(14, line_nbr);

	if ((*node)->n == 0)
		err_handler(15, line_nbr);

	tmp = (*node)->next;

	tmp->n %= (*node)->n;
	free(*node);
	*node = tmp;
}
