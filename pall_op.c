#include "monty.h"

/**
 * pall_op - prints all the values on the stack, starting from the top.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: current line number
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;
	(void) line_number;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}
}
