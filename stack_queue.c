#include "monty.h"
/**
 * _stack - sets sq_flag to stack
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void stack(__attribute__ ((unused)) stack_t **stack,
            __attribute__ ((unused)) unsigned int line
_number)
{
        sq_flag = 0;
}
/**
 * _queue - sets sq_flag to queue
 * @stack: pointer to stack list
 * @line_number: line opcode occurs on
 */
void queue(__attribute__ ((unused))stack_t **stack,
            __attribute__ ((unused))unsigned int line_number)
{
        sq_flag = 1;
}
