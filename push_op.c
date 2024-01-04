#include "monty.h"

/**
 * push_op - pushes an element to the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: current line number
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	int number = 0;
	char *parameter;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_the_stack(*stack);
		exit(EXIT_FAILURE);
	}

	parameter = strtok(NULL, " \t\n");
	if (parameter == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_the_stack(*stack);
		exit(EXIT_FAILURE);
	}

	number = atoi(parameter);
	if (number == 0 && strcmp(parameter, "0") > 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_the_stack(*stack);
		exit(EXIT_FAILURE);
	}

	new_node->n = number;
	new_node->prev = NULL;

	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		*stack = new_node;
	}
}
