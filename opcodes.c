#include "monty.h"


/**
 * push - Pushes a new node onto the stack.
 *
 * @node: Pointer to the new node to be pushed.
 * @value: Unused parameter (required for function pointer compatibility).
 */

void push(stack_t **node, __attribute__((unused))unsigned int value)
{
	stack_t *tmp;

	if (!head)
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
 * pall - Prints all values on the stack, starting from the top.
 *
 * @node: Pointer to the stack.
 * @value: Unused parameter (required for function pointer compatibility).
 */

void pall(stack_t **node,  __attribute__((unused))unsigned int value)
{
	stack_t *tmp;

	if (!node)
		exit(EXIT_FAILURE);
	tmp = *node;
	while (tmp)
	{
		printf("%d\n", (tmp->n));
		tmp = tmp->next;
	}
}
