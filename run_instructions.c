#include "monty.h"

/**
 * run_instruct - executes Monty bytecode instruction based on parameters
 *
 * @stack: pointer to top of the stack.
 * @index_line: current line number executed.
 * @command: (opcode) to be executed.
 */

void run_instruct(stack_t **stack, unsigned int index_line, char *command)
{
	int current_position = 0;

	/* TO ADD: instruction_t -> instruction or instruct {"push", op_push}; ...*/

	while (instruct[current_position].command != NULL)
	{
		/* check command if it matches current instruction */
		if (strcmp(command, instruct[current_position].command) == 0)
		{
			/* exec function associated with matching opcode/command */
			instruct[current_position].f(stack, index_line);
			return;
		}
		current_position++;
	}
	/* else, no matching command/opcode: error message and exit */
	fprintf(stderr, "L%d: unknown instruction %s\n", index_line, command);
	free(line_buffer);
	close(file);
	free_the_stack(stack);
	exit(EXIT_FAILURE);
}
