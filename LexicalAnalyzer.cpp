#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

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
		printf("%d" "tokens were found",result);

		fclose (userFile);
		return result;
	}
}

int parseLine(char * linePtr, char delimiter, char * tokens[], int maxToken)
{
	char *startPtr;
	char *endPtr ;
	char *token ;
	char *numPtr;
	char * countNum;
	int count = 0;
	int   tokenIndex = 0 ;

	while ( *linePtr )
	{
		startPtr = linePtr ;
	
		if ( isalpha(*linePtr) )
		{
			endPtr = findEndOfIdentifier(linePtr) ;
			token = extractIdentifier(startPtr, endPtr) ;
			tokens[tokenIndex] = token ;
			tokenIndex++ ;
			break ;
		}
		else if ( isdigit(*linePtr) )
		{
			numPtr = findEndOfNum(linePtr);
			countNum = extractNum(startPtr, numPtr);
			tokens[count] = countNum;
			count++;
			break;
			
		}
		else if ( *linePtr == delimiter )
		{
			linePtr++ ;
			break ;
		}

	}

	return ;
}

char * findEndOfIdentifier(char * linePtr)
{
	while ( (*linePtr != '\0') && isalpha(*linePtr) )
	{
		linePtr++;
	}

	return linePtr ;
}

char * extractIdentifier(startPtr, endPtr)
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

char * extractNum(startPtr, numPtr)
{
	int length = numPtr - startPtr;
	char* countNum = (char*)malloc(length + 1);
	strncpy(countNum, startPtr, length);
	countNum[length] = '\0';

	return countNum;
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
