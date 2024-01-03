#include "monty.h"

/**
 * pop_op - removes the top element of the stack.
 *
 * @stack: a pointer to the top of the stack.
 * @line_number: current line number
 */
void pop(stack_t **stack, unsigned int line_number)
{
        stack_t *now_node = NULL;

        now_node = *stack;

        if (*stack == NULL)
        {
                fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
                exit(EXIT_FAILURE);
        }
        now_node = now_node->next;
        free(*stack);
        *stack = now_node;
}

