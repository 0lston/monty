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
int is_ascii(int c);

/* lists */
stack_t *create_node(int value);
void free_nodes(void);

/*error printing*/
void err_handler(int err_code, ...);
void err_handler_2(int err_code, ...);

/* opcodes*/
void push(stack_t **node,  __attribute__((unused))unsigned int line_nbr);
void pall(stack_t **node,  __attribute__((unused))unsigned int line_nbr);
void pint(stack_t **node,  unsigned int line_nbr);
void pop(stack_t **node, unsigned int line_nbr);
void swap(stack_t **node, unsigned int line_nbr);
void nop(stack_t **node, unsigned int line_nbr);
void _add(stack_t **node, unsigned int line_nbr);
void _sub(stack_t **node, unsigned int line_nbr);
void _mul(stack_t **node, unsigned int line_nbr);
void _div(stack_t **node, unsigned int line_nbr);
void _mod(stack_t **node, unsigned int line_nbr);
void pchar(stack_t **node, unsigned int line_nbr);
void pstr(stack_t **node, __attribute__((unused))unsigned int line_nbr);
void rotl(stack_t **node, unsigned int line_nbr);
void rotr(stack_t **node, unsigned int line_nbr);
void enqueue(stack_t **node, __attribute__((unused))unsigned int line_nbr);

/* file handling*/
void openFile(const char *filename);
void readFile(FILE *fd);
void parse_line(char *lineptr, int line_nbr, int *format);
void get_function(char *opcode, char *value, int line_nbr, int *format);
void call_f(func op_func, char *op, char *value, int line_nbr, int *format);

#endif
