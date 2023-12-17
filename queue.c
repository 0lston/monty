#include "monty.h"

/**
 * enqueue - Adds a node to the end of the doubly linked list.
 *
 * @node: Pointer to the node to be added.
 * @line_nbr: Unused parameter (required for function pointer compatibility).
 *
 * This function adds a node to the end of the doubly linked list.
 * If the list is empty, the new node becomes the head.
 */

void enqueue(stack_t **node, __attribute__((unused))unsigned int line_nbr)
{

	stack_t *tmp;

	if (!head)
	{
		head = *node;
		return;
	}

	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *node;
	(*node)->next = NULL;
	(*node)->prev = tmp;

}
