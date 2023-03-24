#include "monty.h"



// bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - monty code interpreter
* @argc: argument counter
* @argv: argumment vector(monty file location)
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	int i = 0;
	char *opr;


	instruction_t opcodes[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"\0", NULL}
	} 


	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}

	FILE *f = fopen(argv[1], "r");
	if (!f)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	else
	{
		// content = handle_opcodes(stack, line_number);
		fprintf(stderr, "%s", content);
		fprintf(stderr, "File Open Success!\n");
		exit(EXIT_SUCCESS);
	}

	for (i = 0; opcodes[i].opcode != "\0"; i++)
	{
		if  (opr == opcodes[i].opcode)
			return (opcodes[i].f(stack, line_number))
	
		i++;
		line_number++;
	}


	return (0);
}
