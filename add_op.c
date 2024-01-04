#include "monty.h"

/**
 * add_op - adds the top two elements of the stack
 *
 * @stack: a pointer to the top of the stack
 * @line_number: current line number
 */

void add_op(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	/* Node to free at the end: current stack */
	stack_temp = *stack;

	/* Adding top n value with next n, result in next */
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;

	/* Making next the top */
	*stack = (*stack)->next;

	/* New top prev set to NULL */
	(*stack)->prev = NULL;

	/* Freeing useless previous top node */
	free(stack_temp);
}


