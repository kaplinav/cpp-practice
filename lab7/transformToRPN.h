
#if !defined TRANSFORM_TO_RPN_H
#define TRANSFORM_TO_RPN_H

typedef void(*pFuncJump)(sToken token);

enum eTranStates
{
	stateStart,
	stateNumber,
	stateBinaryOperator,
	stateError,
	stateEnd
};

extern void transformToRPNRun();

#endif // !define TRANSFORM_TO_RPN

