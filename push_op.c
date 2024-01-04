#include "monty.h"

/**
 * only_digits - test if only digits in string
 *
 * @string: a pointer to the string
 * Return: EXIT_SUCCESS on success
 */
int only_digits(char *string)
{
	if (string == NULL)
		return (EXIT_FAILURE);

	char *current = string;
	int position = 0;

	/* Having a - in first position is ok */
	if (position == 0 && current[position] == '-')
		position++;
	while (current[position] != '\0')
	{
		if (!isdigit(current[position]))
			return (EXIT_FAILURE);
		position++;
	}
	return (EXIT_SUCCESS);
}

/**
 * push_op - pushes an element to the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: current line number
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	int number = 0;
	char *parameter;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_the_stack(*stack);
		exit(EXIT_FAILURE);
	}
	parameter = strtok(NULL, " \t\n");
	if (parameter == NULL || only_digits(parameter) == EXIT_FAILURE)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_the_stack(*stack);
		exit(EXIT_FAILURE);
	}

	number = atoi(parameter);
	if ((number == 0 && strcmp(parameter, "0") > 0))
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
