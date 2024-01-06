#include "monty.h"

/**
 * mod_op - multiplies the second top element of the stack
 * with the top element of the stack
 *
 * @stack: a pointer to the top of the stack
 * @line_number: current line number
 */

void mod_op(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_temp = *stack;

	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(stack_temp);
}

