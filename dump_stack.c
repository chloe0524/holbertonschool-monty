#include "monty.h"

/**
 * dump_stack - dumps stack to file.
 *
 * @stack:dumps the stack to text file.
 * @dump: file pointer
 * @line_number: monty script line number
 * @command: command
 */
void dump_stack(stack_t **stack, FILE **dump, unsigned int line_number,
		char *command)
{
	char *dump_name = "dump.log";
	FILE *dump_file = *dump;

	if (dump_file == NULL)
	{
		remove(dump_name); /* first time, remove dump.log if it exists */
		dump_file = fopen(dump_name, "a");
		if (dump_file == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", dump_name);
			return;
		}
		/*
		 ** update dump variable located in main_monty.c
		 ** Otherwise a NULL parameter will always be passed to dump_stack
		 */
		*dump = dump_file;
	}

	stack_t *current_node = *stack;
	int level = 1;

	fprintf(dump_file,
			"\nLine %d, command %s - Current stack start/top/head: %p\n",
			line_number, command,
			(void *)(*stack));
	while (current_node != NULL)
	{
		/* Trick: %*s   , level, "" => prints exactly value of level spaces */
		fprintf(dump_file, "%*s (current: %p) prev %p <- n=%d -> next %p\n",
				level, "",
				(void *)current_node,
				(void *)current_node->prev,
				current_node->n,
				(void *)current_node->next);
		current_node = current_node->next;
		/* each loop: will print 4 more spaces to get indentation */
		level += 4;
	}
}

