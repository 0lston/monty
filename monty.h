#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *head;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


typedef void (*func)(stack_t **, unsigned int);



/* helppers */
int is_number(char *str);

/* lists */
stack_t *create_node(int value);
void free_nodes(void);

/*error printing*/
void err_handler(int err_code, ...);
/*opcodes*/
void push(stack_t **node,  __attribute__((unused))unsigned int value);
void pall(stack_t **node,  __attribute__((unused))unsigned int value);

/* file handling*/
void openFile(const char *filename);
void readFile(FILE *fd);
void parse_line(char *lineptr, int line_nbr);
void get_function(char *opcode, char *value, int line_nbr);
void call_f(func op_func, char *op, char *value, int line_nbr);
#endif
