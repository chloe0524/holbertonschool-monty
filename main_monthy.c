#include "monty.h"

/**
 * main - entry point to the program Monty language interpreter
 *
 * @argc: number of args
 * @argv: array of args
 *
 * Return: EXIT_SUCCESS if success or EXIT_FAILURE if fail
 *
 */

int main(int argc, char *argv[])
{
	FILE *file;
	unsigned int index_line = 0;
	char *line_buffer = NULL, *command;
	ssize_t read;
	size_t Length_buff = 0;
	int ret = EXIT_SUCCESS;
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	stack = NULL;
	while ((read = getline(&line_buffer, &Length_buff, file)) != EOF)
	{
		index_line++;
		if (line_buffer[0] == '#')
			continue;
		command = strtok(line_buffer, " \t\n");
		if (command == NULL)
			continue;
		ret = run_instruct(&stack, command, index_line);

		if (ret != EXIT_SUCCESS)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", index_line, command);
			break;
		}
	}
	free_the_stack(stack);
	free(line_buffer);
	fclose(file);
	return (ret);
}

