#include "monty.h"


/**
 * push - pushes to the stack
 * @stack: stack
 * Return: returns the remaining
 */
stack_t push(stack_t **stack)
{
	stack_t *top = malloc(sizeof(stack_t));


}

/**
 * pop - pops element from the stack
 * @stack: stack
 * Return: returns the remaining
 */
stack_t pop(stack_t **stack)
{
    
}

/**
 * pall - prints all elements in teh stack
 * @stack: stack
 * Return: returns the remaining
 */
stack_t *pall(stack_t **stack)
{
	stack_t *temp = *stack;

	while (temp->next != NULL)
	{
		printf("%d\n", temp->n);
	}

	return (*stack);
}

void usage()
{
	printf("L<%d>: usage: push integer", 0);
	exit(EXIT_FAILURE);
}

int handle_instruction(stack_t **stack, unsigned int line_number)
{
	instruction_t instractions[] = {
		{"push", NULL},
		{"pall", NULL},
		{"pop", NULL} 
	};



}