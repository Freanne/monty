#include "monty.h"
/**
 * pint - print int a top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        printf("L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
/**
 * pop - delete item at top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp = *stack;

    if (*stack == NULL)
    {
        printf("L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    *stack = (*stack)->next;
    if (*stack != NULL)
        (*stack)->prev = NULL;
    free(temp);
}
/**
 * swap - swap top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp = (*stack)->n;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}
/**
 * nop - literally does nothing
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
    
}
