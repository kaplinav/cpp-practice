//#include "other.h"

///////////////////////////////////////////////////
#include <iostream>

#define stop __asm nop

//Вывод на экран элементов массива
//void showIntElements(int* p, size_t n)
//{
//	printf("\n");
//	for (size_t i = 0; i < n; i++)
//	{
//		printf("%d ", *p);
//		p++;
//	}
//	printf("\n");
//}

void printDouble(void* e)
{
	printf("%.2f ", *static_cast<double*>(e));
}

// Вывод на экран элемента типа Int
void printInt(void* e)
{
	printf("%d ", *static_cast<int*>(e));
}

// Вызов указанной функции печати для каждого элемента
void showElements(char* pFirst, size_t n, size_t size, void(*printSpecific)(void*))
{
	printf("\n");
	for (size_t i = 0; i < n; i++)
	{
		char* pCurrent = pFirst + i * size;
		(*printSpecific)(pCurrent);
	}
	printf("\n");
}

void Sort(char* pcFirst, int nNumber, int size, void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
	int i;
	for(i=1; i<nNumber; i++)
		for(int j=nNumber-1; j>=i; j--)
		{
			char* pCurrent = pcFirst+j*size;
			char* pPrevious = pcFirst+(j-1)*size;
			if((*Compare)( pPrevious, pCurrent ) > 0) //требуется
												      //переставить
				(*Swap)( pPrevious, pCurrent );
		}
}

void SwapInt(void* p1, void* p2)
{
	int t = *static_cast<int*>(p1);
	*static_cast<int*>(p1) = *static_cast<int*>(p2);
	*static_cast<int*>(p2) = t;
}

int CmpInt(void* p1, void* p2)
{
	//int nResult;
	return *static_cast<int*>(p1) - *static_cast<int*>(p2);
}

void SwapDouble(void* p1, void* p2)
{
	double t = *static_cast<double*>(p1);
	*static_cast<double*>(p1) = *static_cast<double*>(p2);
	*static_cast<double*>(p2) = t;
}

int CmpDouble(void* p1, void* p2)
{	
	return *static_cast<double*>(p1) - *static_cast<double*>(p2);
}