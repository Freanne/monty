#include "monty.h"
/**
 * add - adds top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

/**
 * sub - subtracts top of stack and second top of stack
 *
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void sub(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}
/**
 * div_op - divide top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void div_op(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't div, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        printf("L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n /= (*stack)->n;
    pop(stack, line_number);
}
/**
 * mul - multiply top of stack and second top of stack
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void mul(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
        {
            printf("L%d: can't mul, stack too short\n", line_number);
            exit(EXIT_FAILURE);
        }

    (*stack)->next->n *= (*stack)->n;
    pop(stack, line_number);
}
/**
 * mod - mod top of stack and second top of stack
 * * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 *
 */
void mod(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        printf("L%d: can't mod, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    if ((*stack)->n == 0)
    {
        printf("L%d: division by zero\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n %= (*stack)->n;
    pop(stack, line_number);
}

