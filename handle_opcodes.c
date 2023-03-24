#include "monty.h"

/**
 * handle_opcodes - function handles opcodes
 * @opcode: passed opcode
 * 
 * Return: returns line_number
 */
int handle_opcodes(stack_t **stack, unsigned int line_number)
{

	int i = 0;
	char *opr;

	FILE *file = fopen(opr, "r");

	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"\0", NULL}
	} 

	for (i = 0; opcodes[i].opcode != '\0'; i++)
	{
		if  (opr == opcodes[i].opcode)
			return (opcodes[i].f(stack, line_number))
	
		i++;
		line_number++;
	}


	if (file != NULL)
	{
		char c;
		int i;
		while ((c = fgetc(file)) != EOF)
		{
			char *str = malloc(sizeof(char) * 20);
			i = 0;
			while (c != '\n')
				str[i++] = c;
			fprintf(stderr, "%s\n", str);
		}
		fclose(file);
	}

	return 0;
}
