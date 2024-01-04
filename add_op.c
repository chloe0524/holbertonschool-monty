#include "monty.h"

/**
 * swap_op - swaps the top two elements of the stack
 *
 * @stack: a pointer to the top of the stack
 * @line_number: current line number
 */

void add_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->n = (*stack)->next->n;
	(*stack)->n = (*stack)->n + (*stack)->n;

}

