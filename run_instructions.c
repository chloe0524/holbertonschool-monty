#include "monty.h"

/**
 * run_instruct - executes Monty bytecode instruction based on parameters
 *
 * @stack: pointer to top of the stack.
 * @index_line: current line number executed.
 * @command: (opcode) to be executed.
 * @parameter: parameter for the instruction (if any).
 */

int run_instruct(char *command, char *parameter)
{
	int index;

	instruction_t instructions[] = {
		{"push", push_op},
		{"pall", pall_op},
		{"pint", pint_op},
		{NULL, NULL}
	};

	for (index = 0; instructions[index].opcode != NULL ; ++index)
	{
		if (strcmp(command, instructions[index].opcode) == 0)
		{
			instructions[index].f(parameter);
			return EXIT_SUCCESS;
		}
	}
	return EXIT_FAILURE;
}


