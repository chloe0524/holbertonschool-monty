#include "monthy.h"

/**
 * free_the_stack - free memory allocated for stack
 *
 * @stack: pointer to top of the stack
 *
 */

void free_the_stack(stack_t *stack)
{
	stack_t *current_node = NULL;

	while (stack != NULL)
	{
		current_node = stack;
		stack = stack->next;
		free(current_node);
	}
}
