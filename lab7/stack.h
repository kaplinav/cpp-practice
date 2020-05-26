
#if !defined STACK_H
#define STACK_H

#include "tokens.h"


struct stack
{
	sToken* stackFirst = nullptr;
	sToken* stackNext = nullptr;
	size_t maxSize = 10;

	void stackInit()
	{
		stackFirst = stackNext = new sToken[maxSize];
	}

	void stackPush(sToken& pushToken)
	{
		if (!stackFirst)
			stackInit();

		*stackNext = pushToken;
		stackNext++;
	}

	sToken stackPop()
	{
		if (!this->stackIsEmpty() )
			return *(--stackNext);
	}

	bool stackIsEmpty()
	{
		return (stackFirst == nullptr) ? true : ( (stackNext < stackFirst) ? true : false) ;
	}

};

extern stack mainStack;
extern stack secondStack;

#endif //!defined STACK_H
