#pragma once

typedef void(*tPtrJump)(char c);

/* States of machine */
enum eStates
{
	start,
	number,
	binaryOperator,
	error,
	end
};

extern eStates getTokensRun(char* c);
