#include "monty.h"

/**
 * pall_op - prints all values on stack, starting from top of the stack 
 * @parameter: unused parameter
 *
 */

void pall_op(char *parameter)
{
	stack_t *current_node = stack;
	(void) parameter;

	while (current_node != NULL)
	{
		printf("%d\n",current_node->n);
		current_node = current_node->next;
	}
}
