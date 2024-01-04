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
	stack_temp = (*stack)->next;

	/* Adding top n value with next n */
	(*stack)->n = (*stack)->next->n + (*stack)->n;
	/* Replacing top next with "next of next" address */
	(*stack)->next = (*stack)->next->next;
	/* New next prev : top stack */
	(*stack)->next->prev = (*stack);
	/* Freeing useless node */
	free(stack_temp);
}

