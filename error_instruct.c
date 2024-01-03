#include "monty.h"
/**
 * error_instruct - handles errors for unknown instructions
 *
 * @stack: double pointer to the beginning of the stack
 * @index_line: index of the line where the error occurred
 * @command: command that produced the error
 * @line_buffer: buffer containing the line from the file
 * @file: file we are reading from
 *
 */

void error_instruct(stack_t **stack, unsigned int index_line, char *command, char *line_buffer, FILE *file)
{
	fprintf(stderr, "L%d: unknown instruction %s\n", index_line, command);
	free(line_buffer);
	fclose(file);
	free_the_stack(*stack);
	exit(EXIT_FAILURE);
}

