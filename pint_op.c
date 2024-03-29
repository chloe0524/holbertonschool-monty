#include "monty.h"

/**
 * pint_op - prints the value at the top of the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: current line number
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
