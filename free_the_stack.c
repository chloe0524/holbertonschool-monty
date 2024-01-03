#include "monty.h"

/**
 * free_the_stack - free memory allocated for stack
 *
 */

void free_the_stack(void)
{
	stack_t *current_node = NULL;

	while (stack != NULL)
	{
		current_node = stack;
		stack = stack->next;
		free(current_node);
	}
}
