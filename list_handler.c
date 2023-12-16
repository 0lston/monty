#include "monty.h"

/**
 * create_node - Creates a new stack node.
 *
 * @value: The value to be stored in the new node.
 *
 * Return: A pointer to the newly created node.
 */

stack_t *create_node(int value)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (!node)
		err_handler(4);

	node->prev = NULL;
	node->next = NULL;
	node->n = value;

	return (node);
}

/**
 * free_nodes - Frees all nodes in the stack.
 */

void free_nodes(void)
{
	stack_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
