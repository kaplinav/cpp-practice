
#include <iostream>
#include <string>
#include <regex>

#include "fileFuncs.h"
#include "OutFuncs.h"
#include "getTokens.h"
#include "tokens.h"
#include "transformToRPN.h"
#include "calculate.h"

#define stop __asm nop

int main(int argc, char* argv[])
{
	if (!checkArgcCount(argc))
	{
		printError("No input file specified");
		return 0;
	}
		
	if (!checkExtension(argv[1]) )
	{
		printError("File type not supported");
		return 0;
	}

	/* Get symbols from input file */
	getStringFromFile(argv[1]);

	/* Initiatialization the array of tokens */
	initTokensArray();

	char c[] = "123+416\n";
	eStates lastState = getTokensRun(c);

	if (lastState == error)
	{
		printError("Syntax error");
		return 0;
	}

	printTokens();
	
	/* Transform tokens sequence to reverse polish notation (RPN) */
	transformToRPNRun();

	calculateRun();

	return 0;
}