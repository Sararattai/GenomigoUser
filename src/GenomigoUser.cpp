#include<stdio.h>
#include<stdlib.h> 

extern int parseTokens(const char * filePath);

int main(int argc, char* argv[])
{  
	const char * filePath = "C:/Users/Saranya/Development/GenomigoUser/input/Users.csv";
	//const char * filePath = "Users.csv";
	parseTokens(filePath);
	return 0;
}
