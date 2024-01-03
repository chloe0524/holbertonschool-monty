#ifndef MONTY_HEADER
#define MONTY_HEADER

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

/* DATA STRUCTURES */

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

/* GLOBAL VARIABLE */

extern stack_t *stack;

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

void free_the_stack(stack_t *stack);
void run_instruct(stack_t **stack, unsigned int index_line, char *command, char *parameter);
void error_instruct(stack_t **stack, unsigned int index_line, char *command, char *line_buffer, FILE *file);
int is_digit(char *opcode);
void push_op(stack_t **stack, unsigned int line_number);

#endif /* MONTY_HEADER */
