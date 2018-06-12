#include<stdio.h>
#include<stdlib.h> 

extern int parseTokens(const char * filePath);

int main(int argc, char* argv[])
{  
	const char * filePath = "C:\\Users\\Saranya\\Development\\Genomigo_cpp\\Genomigo_cpp\\user.csv";
	parseTokens(filePath);
	return;
}