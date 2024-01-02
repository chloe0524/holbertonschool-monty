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
	int file;
	unsigned int index_line = 0;
	stack_t *stack = NULL;
	char *line_buffer = NULL, *command;
	ssize_t read;
	size_t lenght_buff = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = open(argv[1], O_RDONLY);
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	while ((read = getline(&line_buffer, &lenght_buff, file)) != EOF)
	{
		index_line++;

		command = strtok(line_buffer, " \n");
		if (command == NULL)
		{
			continue;
		}
		instruc_exec(&stack, index_line);
	}
	free(line_buffer);
	close(file);
	free_the_stack(&stack);
	return (EXIT_SUCCESS);
}
