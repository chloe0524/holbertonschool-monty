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

stack_t *stack = NULL;

int main(int argc, char *argv[])
{
	FILE * file;
	unsigned int index_line = 0;
	char *line_buffer = NULL, *command, *parameter;
	ssize_t read;
	size_t lenght_buff = 0;
	int ret=EXIT_SUCCESS;

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

	while ((read = getline(&line_buffer, &lenght_buff, file)) != EOF)
	{
		index_line++;

		command = strtok(line_buffer, " \t\n");
		if (command == NULL)
		{
			continue;
		}
		parameter = strtok(NULL, " \t\n");
		ret=run_instruct(command, parameter);
		if (ret != EXIT_SUCCESS)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", index_line, command);
			break;
		}
	}
	free(line_buffer);
	free_the_stack();
	fclose(file);
	return (ret);
}

