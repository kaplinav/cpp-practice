
/*
This file contain state machine for getting tokens from input string
*/

#include "getTokens.h"
#include "tokens.h"

eStates state;

/* States of machine */
void stateStart(char c);
void stateNumber(char c);
void stateBinaryOperator(char c);
void stateError(char c);
void stateEnd(char c);

tPtrJump jump[] = { stateStart, stateNumber, stateBinaryOperator, stateError, stateEnd };

/* Initialize the machine */
void stateMachineInit()
{
	state = start;
}

/* Machine work */
eStates getTokensRun(char* c)
{
	stateMachineInit();

	do
	{
		/* call the functions with transition rule */
		jump[state](*c);

		/* shift the pointer to next symbol*/
		c++;

	} while (state != end && state != error);

	return state;
}

void stateStart(char c)
{
	/* Current state: Start */
	if (c >= '0' && c <= '9')
	{
		state = number;
		/* Add new token with type 'Number' */
		addNewToken(c, tokNumber);
	}
	else if (c == '\n')
		state = end;

	else
		state = error;
}

void stateNumber(char c)
{
	/* Current state: Number */
	if (c >= '0' && c <= '9')
	{
		state = number;
		/* add char symbol to token  */
		addSymbolToToken(c);
	}
	else if (c == '+')
	{
		state = binaryOperator;
		/* Add new token with type 'Binary operator' */
		addNewToken(c, tokBinaryOperator);
	}
	else if (c == '\n')
		state = end;

	else
		state = error;
}

void stateBinaryOperator(char c)
{
	/* Current state: Binary Operator */
	if (c >= '0' && c <= '9')
	{
		state = number;
		/* Add new token with type 'Number' */
		addNewToken(c, tokNumber);
	}
	else if (c == '+')
		state = error;

	else if (c == '\n')
		state = end;

	else
		state = error;
}

void stateError(char c) { }

void stateEnd(char c) { }
