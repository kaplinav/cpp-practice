
#if !defined TOKENS_H 
#define TOKENS_H

/* Type of token */
enum eType
{
	tokBinaryOperator,
	tokNumber
};

struct sToken
{
	char* pFirst;
	char* pNext;
	size_t size;
	size_t addSize;
	eType type;
};

/* Add one char to token */
void addSymbolToToken(char c);

/* Initiatialization the array of tokens */
void initTokensArray();

/* Return count of tokens */
size_t getTokensCount();

/* Add new token with specified type to array */
void addNewToken(char c, eType type);

/* For debug: printing the array of tokens */
void printTokens();


sToken* getFirstTokenPtr();

#endif // !defined TOKENS_H 