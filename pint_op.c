#include "monty.h"

/**
 * pint_op - prints the value at the top of the stack
 * @parameter: unused parameter
 *
 */
void pint_op(char *parameter)
{
	(void) parameter;

	printf("%d\n",stack->n);
}

