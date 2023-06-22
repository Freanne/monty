#include "monty.h"
/**
 * pchar - prints the ASCII value of a number
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void pchar(stack_t **stack, unsigned int line_number)
{
    int value = (*stack)->n;

    if (*stack == NULL)
    {
        printf("L%d: can't pchar, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

   
    if (value < 0 || value > 127)
    {
        printf("L%d: can't pchar, value out of range\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%c\n", value);
}
/**
 * pstr - print string starting a top of stack
 * @stack: linked list for stack
 * @line_number: line number opcode occurs on
 */
void pstr(stack_t **stack, __attribute__ ((unused))unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
    {
        if (current->n == '0')
            break;

        printf("%c", current->n);
        current = current->next;
    }

    printf("\n");
}
/**
 * rotl - rotates the list left
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void rotl(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
    stack_t *last = *stack;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    
    while (last->next != NULL)
        last = last->next;

    last->next = *stack;
    (*stack)->prev = last;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last->next->next = NULL;
}
/**
 * rotr - rotates the list right
 * @stack: pointer to the top of the stack
 * @line_number: the index of the current line
 *
 */
void rotr(stack_t **stack, __attribute__ ((unused)) unsigned int line_number)
{
    stack_t *last = *stack;

    if (*stack == NULL || (*stack)->next == NULL)
        return;

    
    while (last->next != NULL)
        last = last->next;

    last->prev->next = NULL;
    last->prev = NULL;
    last->next = *stack;
    (*stack)->prev = last;
    *stack = last;
}

