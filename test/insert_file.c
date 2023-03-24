#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#define FILENAME_SIZE 1024
#define MAX_LINE 2048

int main(int argc, char **argv)
{
	FILE *file, *temp;

	char filename[FILENAME_SIZE];
	char temp_filename[FILENAME_SIZE];

	char buffer[MAX_LINE];
	char replace[MAX_LINE];
	int replace_line = 0;
	

	// prompting the user
	printf("File: ");
	scanf("%s", filename);
	
	strcpy(temp_filename, "__temp__");
	strcat(temp_filename, filename);
	
	printf("Replace Line Number: ");
	scanf("%d", &replace_line);

	fflush(stdin);	// flushing the new line character in the standard input
	fprintf(stderr, "New Line: ");
	fgets(replace, MAX_LINE, stdin);
	

	file = fopen(filename, "r");
	temp = fopen(temp_filename, "w");
	
	if (file == NULL || temp == NULL)
	{
		printf("Error opening file(s).\n");
		return 1;
	}
	
	bool keep_reading = true;
	int current_line = 1;
	
	do {
		fgets(buffer, MAX_LINE, file);
		if (feof(file)) keep_reading = false;
		else if (current_line == replace_line)
			fputs(replace, temp);
		else
			fputs(buffer, temp);
		current_line++;
	} while (keep_reading);

	fclose(file);
	fclose(temp);

	remove(filename);
	rename(temp_filename, filename);

	return (0);
}
