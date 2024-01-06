#include "monty.h"

/**
 * div_op - divides the second top element of the stack
 * by the top element of the stack
 *
 * @stack: a pointer to the top of the stack
 * @line_number: current line number
 */

void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%i: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%i: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	stack_temp = *stack;

	(*stack)->next->n = (*stack)->next->n / (*stack)->n;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(stack_temp);
}

