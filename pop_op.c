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
		fprintf(stderr, "L%i: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next == NULL)
	{
		free(*stack);
		*stack = NULL;
		return;
	}
	stack_temp = (*stack);

	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(stack_temp);
}
