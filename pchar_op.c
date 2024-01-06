#include "monty.h"
#include <ctype.h>

/**
 * pchar - Prints the char at the top of the stack, followed by a new line.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed (not used here).
 */
void pchar_op(stack_t **stack, unsigned int line_number)
{
	char ascii_char = '0';

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	ascii_char = (*stack)->n;

	if (!isascii(ascii_char))
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%c\n", ascii_char);
	*stack = (*stack)->next;
}

