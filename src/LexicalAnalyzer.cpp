#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

struct User parseLine(char * linePtr, char delimiter);
char * extractToken(char *startPtr, char *endPtr);
char * findEndOfIdentifier(char * linePtr);
char * extractNum(char * startPtr, char *  numPtr);
char * findEndOfNum(char * linePtr);
char * extractNum(char * startPtr, char *  numPtr);
void skipDelimiter(struct TextLineParser * textLineParserPtr, char delimiter);
void getNextToken(struct TextLineParser * textLineParserPtr, char delimiter);
void skipDt(struct TextLinePrser *textLineParser, char space);

#define	VALID	 0
#define	INVALID	 -1


struct TextLineParser
{
	char * 	currentLinePtr ;
	char * 	currentToken ;
};

struct User
{
	int  	userId;
	char * 	firstName;
	char * 	lastName;
	char * 	address;
	char * 	city;
	int  	zip;

	char  *	phone;
	int  	DOB;
};

int parseTokens(const char * filePath)
{
	int maxToken = 10;
	char * tokens[10];
	char * linePtr;
	char line[400];
	struct User user ;


	char delimiter = ',';

	char space = '-';

	FILE * userFile;

	userFile = fopen(filePath,"r");

	if (userFile == NULL)
	{
		printf("Unable to open the file !!!");
		return 2;
	}

	linePtr = fgets(line, sizeof(line), userFile);

	while (true)
	{
		linePtr = fgets(line, sizeof(line), userFile);

		if (linePtr == NULL)
		{
			break;
		}

		user = parseLine(linePtr, delimiter);
		//printf("%d" "tokens were found", result);

	}
	fclose(userFile);
	return 0;
}


struct User parseLine(char * linePtr, char delimiter)
{
	struct User	    user ;
	struct TextLineParser	textLineParser ;

	textLineParser.currentLinePtr = linePtr ;
	
	getNextToken(&textLineParser, delimiter) ;
	user.userId = atoi(textLineParser.currentToken) ;
	skipDelimiter(&textLineParser, delimiter) ;

	getNextToken(&textLineParser, delimiter) ;
	user.firstName = textLineParser.currentToken ;
	skipDelimiter(&textLineParser, delimiter) ;

	getNextToken(&textLineParser, delimiter);
	user.lastName = textLineParser.currentToken;
	skipDelimiter(&textLineParser, delimiter);

	getNextToken(&textLineParser, delimiter);
	user.address = textLineParser.currentToken;
	skipDelimiter(&textLineParser, delimiter);

	getNextToken(&textLineParser, delimiter);
	user.city = textLineParser.currentToken;
	skipDelimiter(&textLineParser, delimiter);

	getNextToken(&textLineParser, delimiter);
	user.zip = atoi(textLineParser.currentToken);
	skipDelimiter(&textLineParser, delimiter);

	getNextToken(&textLineParser, delimiter);
	user.phone = textLineParser.currentToken;
	skipDelimiter(&textLineParser, delimiter);

	getNextToken(&textLineParser, delimiter);
	user.phone = textLineParser.currentToken;
	skipDt(&textLineParser, space);

	printf("%d %s %s %s %s %s %d % d", user.userId, user.firstName, user.lastName, user.address, user.city,user.phone);

	printf("%y %m %d", user.DOB);

	return user ;
}

void getNextToken(struct TextLineParser * textLineParserPtr,char delimiter)
{
	char *startPtr = textLineParserPtr->currentLinePtr ;
	char *endPtr ;
	

	while ( (*textLineParserPtr->currentLinePtr != '\0') && (*textLineParserPtr->currentLinePtr != delimiter) )
	{
		textLineParserPtr->currentLinePtr++ ;
	}

	endPtr = textLineParserPtr->currentLinePtr ;

	char* token = extractToken(startPtr, endPtr) ;
	textLineParserPtr->currentToken = token ;
	return ;
}

char * extractToken(char *startPtr, char *endPtr)
{
	int length = endPtr - startPtr;
	char* token = (char*)malloc(length + 1);
	strncpy(token, startPtr, length);
	token[length] = '\0';

	return token;
}


void skipDelimiter(struct TextLineParser * textLineParserPtr, char delimiter)
{
	if ( *textLineParserPtr->currentLinePtr == delimiter )
	{
		textLineParserPtr->currentLinePtr++ ;
	}

	return ;
}

void skipDt(struct TextLineParser * textLineParserPtr, char space)
{
	if (*textLineParserPtr->currentLinePtr == space)
	{
		textLineParserPtr->currentLinePtr++;
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
*/

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
