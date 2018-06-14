#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

int parseLine(char * linePtr, char delimiter, char * tokens[], int maxToken);
char * extractIdentifier(char *startPtr, char *endPtr);
char * findEndOfIdentifier(char * linePtr);
char * extractNum(char * startPtr, char *  numPtr);
char * findEndOfNum(char * linePtr);
char * extractNum(char * startPtr, char *  numPtr);

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


	char delimiter = ',';

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

		int result = parseLine(linePtr, delimiter, tokens, maxToken);
		printf("%d" "tokens were found", result);

		fclose (userFile);
		return result;
	}
}

int parseLine(char * linePtr, char delimiter, char * tokens[], int maxToken)
{
	char *startPtr;
	char *endPtr ;
	char *numPtr;
	char * token;
	int   tokenIndex = 0 ;


	while ( *linePtr )
	{
		startPtr = linePtr ;
	
		if ( isalpha(*linePtr) )
		{
			endPtr = findEndOfIdentifier(linePtr) ;
			token = extractIdentifier(startPtr, endPtr) ;
			tokens[tokenIndex] = token;
			int digit = atoi(token);
			tokenIndex++ ;
			break ;
		}
		else if ( isdigit(*linePtr) )
		{
			numPtr = findEndOfNum(linePtr);
			token = extractNum(startPtr, numPtr);
			tokens[tokenIndex] = token;
			int digit = atoi(token);
			tokenIndex++;
			break;
			
		}
		else if ( *linePtr == delimiter )
		{
			linePtr++ ;
			break ;
		}

	}

	return tokenIndex ;
}

char * findEndOfIdentifier(char * linePtr)
{
	while ( (*linePtr != '\0') && isalpha(*linePtr) )
	{
		linePtr++;
	}

	return linePtr ;
}

char * extractIdentifier(char *startPtr, char *endPtr)
{
	int length = endPtr - startPtr;
	char* token = (char*)malloc(length + 1);
	strncpy(token, startPtr, length);
	token[length] = '\0';

	return token;
}

char * findEndOfNum(char * linePtr)
{
	while ((*linePtr != '\0') && isdigit(*linePtr))
	{
		linePtr++;
	}

	return linePtr;
}

char * extractNum(char * startPtr, char *  numPtr)
{
	int length = numPtr - startPtr;
	char* token = (char*)malloc(length + 1);
	strncpy(token, startPtr, length);
	token[length] = '\0';

	return token;
}

	/*
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
	*/
