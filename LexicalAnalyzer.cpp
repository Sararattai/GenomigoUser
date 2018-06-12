#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include<string.h>

int parseLine(char * linePtr, char delimiter, char * tokens[], int maxToken);

struct User
{
	char * firstName;
	char * lastName;
	int * DOB;
	char * userId;
};

int parseTokens(const char * filePath)
{
	struct User;
	int maxToken = 10;
	char * tokens[10];
	char * linePtr;
	char line[400];
	char delimiter;

	delimiter = ',';

	FILE * userFile;

	userFile = fopen(filePath,"r");

	if (userFile == NULL)
	{
		printf("Unable to open the file !!!");
		return 2;
	}

	while (true)
	{
		linePtr = fgets(line, sizeof(line), userFile);

		if (linePtr == NULL)
		{
			break;
		}

		int result = parseLine(linePtr, ',', tokens, maxToken);
		printf("%d" "tokens were found",result);

		fclose (userFile);
		return result;
	}

	int parseLine(char * linePtr, char delimiter, char * tokens[], int maxToken)
	{
		char* srcStr = (char*)malloc(strlen(linePtr) + 1);
		strcpy(srcStr, lineptr);
		int strlen = 0;
		int tokenCount = 0;

		if (srcStr[strlen] != delimiter && scrStr[strlen] != '\0' && scrStr[strlen] != 'espace')
		{
			tokens[tokenCount] = char*malloc(size of(char) * strlen + 1);
			tokens[tokenCount] = &scrStr[strlen];
			tokenCount++;
		}
		else
		{
			strlen++;
		}
	}