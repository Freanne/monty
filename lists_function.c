#include "monty.h"
/*
* executeByteCode - execute the ByteCode
* @filename : name of the file which contain stack function
* Return: Execute code.
*/

void executeByteCode(const char *filename)
{
    char buffer[BUFFER_SIZE];
    char *instruction;
    unsigned int line = 1;
    stack_t *stack = NULL;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while (fgets(buffer, BUFFER_SIZE, file) != NULL)
    {
        
        buffer[strcspn(buffer, "\n")] = '\0';
        
        instruction = strtok(buffer, " ");

        if (instruction != NULL)
        {
            processInstruction(instruction, line, &stack);
        }

        line++;
    }

    fclose(file);
}
/*
*  processInstruction - The process of instruction
*   @instruction: ...
*  @line: ...
*  @stack: ...
*  Return: ....
*/
void processInstruction(const char *instruction, unsigned int line, stack_t **stack)
{
    instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
        {"pint", pint},
        {"pop", pop},
        {"nop", nop},
        {"swap", swap},
        {"add", add},
        {"sub", sub},
        {"mul", mul},
        {"div_op", div_op},
        {"mod", mod},
        {"pchar", pchar},
    	{"pstr", pstr},
    	{"rotl", rotl},
    	{"rotr", rotr},
	{"stack", stack},
	{"queue", queue},
	{NULL, NULL}};

    int i = 0;
    
    while (instructions[i].opcode != NULL)
    {
        if (strcmp(instruction, instructions[i].opcode) == 0)
        {
            instructions[i].f(stack, line);
            return;
        }
        i++;
    }

    printf("L%d: unknown instruction %s\n", line, instruction);
    exit(EXIT_FAILURE);
}
/**
 * push - push int to a stack
 * @stack: linked lists for monty stack
 * @line_number: number of line opcode occurs on
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *arg = strtok(NULL, " ");
    stack_t *new_node = malloc(sizeof(stack_t));

    if (arg != NULL)
    {
        int value = atoi(arg);

        if (value == 0 && strcmp(arg, "0") != 0)
        {
            printf("L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }

       
        if (new_node == NULL)
        {
            printf("Error: malloc failed\n");
            exit(EXIT_FAILURE);
        }

        new_node->n = value;
        new_node->prev = NULL;
        new_node->next = *stack;

        if (*stack != NULL)
            (*stack)->prev = new_node;

        *stack = new_node;
    }
    else
     {
        printf("L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
}
/**
 * pall - print all function
 * @stack: pointer to linked list stack
 * @line_number: number of line opcode occurs on
 */
void pall(stack_t **stack,  __attribute__ ((unused))unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

