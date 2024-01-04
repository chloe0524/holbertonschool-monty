#include "monty.h"

/**
 * run_instruct - executes Monty bytecode instruction based on parameters
 *
 * @stack: pointer to top of the stack
 * @command: (opcode) to be executed
 * @line_number: current line number executed
 *
 * Return: EXIT_FAILURE if failure
 */

int run_instruct(stack_t **stack, char *command, unsigned int line_number)
{
	int index;

	instruction_t instructions[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{"pop", pop_op},
		{"nop", nop_op},
		{"swap", swap_op},
		{"NULL", NULL},
	};

	for (index = 0; instructions[index].opcode != NULL ; ++index)
	{
		if (strcmp(command, instructions[index].opcode) == 0)
		{
			instructions[index].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
