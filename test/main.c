#include "../monty.h"

/**
 * main - testing function
 * 
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	int counter = 0;
	FILE *f;
	char *content;
	f= fopen(argv[1], "r");
	char buffer[1024];

	while (fgets(buffer, 1024, f) != NULL)
	{
		content = strtok(buffer, " ");
		fprintf(stdout, "%d : %s", counter, content);
		content = strtok(NULL, " ");
		if (content)
			fprintf(stdout, " -> %d\n", atoi(content));
		counter++;
	}
	fclose(f);
	

	return (0);
}
