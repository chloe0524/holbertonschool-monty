#include "monty.h"

/**
 * pchar_op - prints the character at the top of the stack
 *
 * @stack: a pointer to the top of the stack
 * @line_number: current line number
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	char ascii_char;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	ascii_char = (*stack)->n;
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%i: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", ascii_char);
	*stack = (*stack)->next;
}

