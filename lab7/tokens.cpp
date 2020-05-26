
#include <cstdio>
#include "tokens.h"

size_t tokensMax;
sToken* nextToken;
sToken* firstToken;

/* Add one char to token */
void addSymbolToToken(char c)
{
	*nextToken->pNext = c;
	nextToken->pNext++;
	*nextToken->pNext = '\0';
}

/* Initiatialization the array of tokens */
void initTokensArray()
{
	tokensMax = 10;
	firstToken = nextToken = new sToken[tokensMax];
	firstToken->pFirst = firstToken->pNext = nullptr;
}

/* Return count of tokens */
size_t getTokensCount()
{
	return nextToken - firstToken + 1;
}

/* Add new token with specified type to array */
void addNewToken(char c, eType type)
{
	if (firstToken->pFirst)
		nextToken++;
	
	nextToken->type = type;
	nextToken->size = 30;
	nextToken->pFirst = nextToken->pNext = new char[nextToken->size];
	addSymbolToToken(c);
}

void printTokens()
{
	size_t n = getTokensCount();
	printf("\n");

	for (size_t i = 0; i < n; i++)
	{
		if (firstToken[i].type == tokNumber)
			printf("(Number) ");
		else
			printf("(Binary operator) ");

		printf("(%s)\n", firstToken[i].pFirst );

	}
}

sToken* getFirstTokenPtr()
{
	return firstToken;
}