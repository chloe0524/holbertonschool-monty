#include "monty.h"

/**
 * is_digit - Checks if a string represents an integer.
 *
 * @opcode: the string to check.
 *
 * Return: 1 if the string is an integer, -1 otherwise.
 */

int is_digit(char *opcode)
{
	if (!opcode)
		return 0;

	for (; *opcode; ++opcode)
	{
		if (!isdigit(*opcode) && *opcode != '-')
			return 0;
	}
	return 1;
}

/**
 * push - pushes an element to the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: the line number being executed (not used here).
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = NULL;
	char *number_string = NULL;
	int number = 0;

	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	number_string = strtok(NULL, " \t\n");

	if (number_string == NULL || is_digit(number_string) == -1)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	number = atoi(number_string);

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
