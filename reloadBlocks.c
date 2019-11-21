#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printBlockData(char *line);
void printArrow();
void printBlocks();
void getDB();

int main() {
	getDB();
	printBlocks();
	return 0;
}

void printBlocks()
{
	char line[500];
	FILE * f = fopen("./blocks", "rb");
	int i = 0;
	while (fgets(line, sizeof(line), f)) {
		if (i++)
			printArrow();
		printBlockData(line);
	}
	fclose(f);
}

void printBlockData(char *line)
{
	char *token = strtok(line, " ");
	int i = 0;
	while (token != NULL)
	{
		printf("%s ", token);
		if (i++ % 2 == 1)
			printf("\n");
		token = strtok(NULL, " ,\n");
	}
}

void printArrow()
{
	printf("\t\t\t\t|\n\t\t\t\t|\n\t\t\t\t|\n\t\t\t\tV\n");
}

void getDB()
{
	system("./getBlocks");
}