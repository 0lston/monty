#include "monty.h"


/**
 * push - Pushes a new node onto the stack.
 *
 * @node: Pointer to the new node to be pushed.
 * @line_nbr: Unused parameter (required for function pointer compatibility).
 */

void push(stack_t **node, __attribute__((unused))unsigned int line_nbr)
{
	stack_t *tmp;


	if (head == NULL)
	{
		head = *node;
		return;
	}

	tmp = head;
	head = *node;
	head->next = tmp;
	tmp->prev = head;
}


/**
 * pop - Removes the top element of the stack.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the pop instruction.
 *
 * This function removes the top element of the stack. If the stack is
 * empty, it calls the err_handler_2 function to handle the error.
 */

void pop(stack_t **node, unsigned int line_nbr)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL)
		err_handler(7, line_nbr);

	tmp = *node;
	*node = (*node)->next;
	if (*node != NULL)
		(*node)->prev = NULL;

	free(tmp);
}

/**
 * swap - Swaps the top two elements of the stack.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the swap instruction.
 *
 * This function swaps the positions of the top two nodes in the stack.
 * If the stack has fewer than two nodes, it calls err_handler_2 to handle
 * the error.
 */

void swap(stack_t **node, unsigned int line_nbr)
{
	stack_t *first, *second;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		err_handler_2(8, line_nbr);

	first = *node;
	second = first->next;

	/* Adjust the prev and next pointers for the first node */
	first->prev = second;
	first->next = second->next;


	/* Adjust the prev and next pointers for the second node */
	second->prev = NULL;
	second->next = first;

	/* Update the 3d node if necessary */
	if (first->next != NULL)
		first->next->prev = first;

	/* Update the top of the stack */
	*node = second;
}

/**
 * rotl - Rotates the stack to the top.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the rotl instruction.
 *
 * This function rotates the stack, making the top element the last one
 * and the second top element the first one.
 */

void rotl(stack_t **node, __attribute__((unused))unsigned int line_nbr)
{

	stack_t *tmp, *second;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		return;

	tmp = *node;
	while (tmp->next)
		tmp = tmp->next;

	second = (*node)->next;
	second->prev = NULL;

	tmp->next = *node;
	(*node)->next = NULL;
	(*node)->prev = tmp;
	*node = second;
}

/**
 * rotr - Rotates the stack to the bottom.
 *
 * @node: Pointer to the top of the stack.
 * @line_nbr: Line number associated with the rotr instruction.
 *
 * This function rotates the stack, making the last element the top one
 * and adjusting the other pointers accordingly.
 */

void rotr(stack_t **node, __attribute__((unused))unsigned int line_nbr)
{
	stack_t *tmp;

	if (node == NULL || *node == NULL || (*node)->next == NULL)
		return;

	tmp = *node;
	while (tmp->next)
		tmp = tmp->next;

	(*node)->prev = tmp;
	tmp->next = *node;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	*node = tmp;
}
