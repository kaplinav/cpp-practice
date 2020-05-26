
#include "tokens.h"
#include "stack.h"
#include "transformToRPN.h"

#define stop __asm nop

eTranStates state;

size_t tokensCount;
size_t incrementCounter;

void startJump(sToken token);
void NumberJump(sToken token);
void BinaryOperatorJump(sToken token);
void errorJump(sToken token);
void endJump(sToken token);

pFuncJump funcJump[] = { startJump, NumberJump, BinaryOperatorJump, errorJump, endJump };

void transformToRPNInit()
{
	state = stateStart;
}

void transformToRPNRun()
{
	sToken* token = getFirstTokenPtr();
	tokensCount = getTokensCount();
	incrementCounter = 0;

	do
	{
		/* call the functions with transition rule */
		funcJump[state](*token);

		/* shift to the next token*/
		token++;
		incrementCounter++;

	} while (state != stateEnd && state != stateError);

}

void startJump(sToken token)
{
	/* Current state: Start */
	if (token.type == tokNumber)
	{
		state = stateNumber;
		mainStack.stackPush(token);
	}
	else
	{
		state = stateError;
	}
}

void NumberJump(sToken token)
{
	/* Current state: Number */
	if (incrementCounter == tokensCount)
	{
		state = stateEnd;
		
		if (!secondStack.stackIsEmpty())
		{
			sToken t = secondStack.stackPop();
			mainStack.stackPush(t);
		}

	}
	if (token.type == tokBinaryOperator)
	{
		state = stateBinaryOperator;
		
		if (!secondStack.stackIsEmpty())
		{
			sToken t = secondStack.stackPop();
			mainStack.stackPush(t);
		}
		secondStack.stackPush(token);
	}
	else
	{
		state = stateError;
	}
}

void BinaryOperatorJump(sToken token)
{
	/* Current state: Binary Operator */
	if (token.type == tokNumber)
	{
		state = stateNumber;
		mainStack.stackPush(token);
	}
	else
	{
		state = stateError;
	}
}

void errorJump(sToken token)
{

}

void endJump(sToken token)
{

}