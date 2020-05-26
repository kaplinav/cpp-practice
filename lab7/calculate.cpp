
#include "stack.h"
#include <cmath>

#define stop __asm nop

void calculateRun()
{
	if (mainStack.stackIsEmpty())
		return;


	for (size_t i = 0; i < 3; i++)
	{
		if (mainStack.stackFirst[i].type == tokBinaryOperator)
		{
			int a = 0;
			
			int counter = 0;
			
			mainStack.stackFirst[i - 2].pNext--;
			do
			{
				int p = 10;
				p = pow(p, counter);

				
				a += (static_cast<int>(*mainStack.stackFirst[i - 2].pNext) - 48) * p;
				counter++;
				mainStack.stackFirst[i - 2].pNext--;
			} while (counter < 3);


			int b = 0;
			counter = 0;


			mainStack.stackFirst[i - 1].pNext--;
			do
			{
				int p = 10;
				p = pow(p, counter);


				b += (static_cast<int>(*mainStack.stackFirst[i - 1].pNext) - 48) * p;
				counter++;
				mainStack.stackFirst[i - 1].pNext--;
			} while (counter < 3);

			stop
		}

		
	}
}