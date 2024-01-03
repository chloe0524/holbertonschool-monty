#include "monty.h"

/**
 * run_instruct - executes Monty bytecode instruction based on parameters
 *
 * @stack: pointer to top of the stack.
 * @index_line: current line number executed.
 * @command: (opcode) to be executed.
 * @parameter: parameter for the instruction (if any).
 */

void run_instruct(stack_t **stack, unsigned int index_line, char *command, char *parameter)
{
	int index;

	instruction_t instructions[] = {
		{"push", push_op},
	};

	for (index = 0; instructions[index].opcode; ++index)
	{
		if (strcmp(command, instructions[index].opcode) == 0)
		{
			instructions[index].f(stack, index_line);
			return;
		}
	}

	error_instruct(stack, index_line, command, parameter, NULL);
}

