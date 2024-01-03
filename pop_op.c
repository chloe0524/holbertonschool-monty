#include "monty.h"

/**
 * pop_op - removes the top element of the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: current line number
 */
void pop_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
	stack_t *now_node = *stack;
	*stack = (*stack)->next;
	free(now_node);
}


