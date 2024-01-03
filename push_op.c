#include "monty.h"

/**
 * push - pushes an element to the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @parameter: parameter for op.
 */

void push_op(char *parameter)
{
	stack_t *new_node = NULL;
	int number = 0;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	number = atoi(parameter);
	
	new_node->n = number;
	new_node->prev = NULL;

	if (stack == NULL)
	{
		new_node->next = NULL;
		stack = new_node;
	}
	else
	{
		new_node->next = stack;
		stack->prev = new_node;
		stack = new_node;
	}
}
